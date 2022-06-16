/*
Hello, World! example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for writing a program for Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
#include "drawing.h"
#include "track.h"
#include "sprites.h"

// make an instance of arduboy used for many functions
Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);

const byte musicScore[] PROGMEM = {0x90, 83, 0, 75, 0x80, 0x90, 88, 0, 225, 0x80, 0xf0};

#define DRAW_DISTANCE 35
#define MAX_FUEL 1000
#define FUEL_USAGE 1
#define COLLISION_INDEX 4

const int cameraHeight = 1200;
int roadW = 2800;
int segL = 256;
float camD = 0.9;
int height;
int width;
int cameraX = 0;
int targetLane = 1;
int fuel = MAX_FUEL;
char isDriving = 0;
char isGameOver = 0;
int notDrivingTimer = 0;
char colission = 0;
char colissionMask = 0;
int score = 0;
char isGameStarted = 0;

void project(
    float x, float y, float z,
    int camX, int camY, int camZ,
    int *X, int *Y, int *W,
    float *S)
{
  float scale = camD / (z - camZ);

  *X = (1 + scale * (x - camX)) * width / 2;
  *Y = (1 - scale * (y - camY)) * height / 2;
  *W = scale * roadW * width / 2;
  *S = scale;
}

void render_road()
{
  int lastX, lastY, lastW;

  float baseX = 0, dx = 0;
  int z = 0;

  for (int i = 0; i < DRAW_DISTANCE; i++)
  {
    segment *seg = get_segment(i);

    int x = 0, y = 0, w = 0;
    float scale = 0;
    project(0, 0, z, (float)cameraX - baseX, cameraHeight, 0, &x, &y, &w, &scale);

    seg->x = x;
    seg->y = y;
    seg->scale = scale;

    baseX += dx;
    dx += seg->curve;

    if (i > 1)
    {
      draw_segment(lastX, lastY, lastW, x, y, w, seg->index);
    }

    lastX = x;
    lastY = y;
    lastW = w;
    z += segL;
  }

  for (int i = DRAW_DISTANCE - 1; i > 0; i--)
  {
    segment *seg = get_segment(i);

    if (seg->sprite)
    {
      unsigned char leftSprite = seg->sprite >> 4;
      unsigned char rightSprite = seg->sprite & 0xF;

      if (leftSprite != SPRITE_NONE)
      {
        int spriteX =
            seg->x -
            (seg->scale *
             roadW *
             width * 1.25) /
                2;

        draw_sprite(
            seg->sprite,
            spriteX,
            seg->y);
      }

      if (rightSprite != SPRITE_NONE)
      {
        int spriteX =
            seg->x +
            (seg->scale *
             roadW *
             width * 1.25) /
                2;

        draw_sprite(
            seg->sprite,
            spriteX,
            seg->y);
      }
    }

    if (seg->objects)
    {
      char left = OBJECT_LEFT(seg->objects);
      char middle = OBJECT_MIDDLE(seg->objects);
      char right = OBJECT_RIGHT(seg->objects);

      if (right)
      {
        int spriteX =
            seg->x +
            (seg->scale *
             roadW *
             width * 0.33) /
                2;

        draw_object(
            right,
            spriteX,
            seg->y);

        if (i == COLLISION_INDEX && spriteX > width / 2 - 8 && spriteX < width / 2 + 8)
        {
          colission = right;
          colissionMask = 0b00111100;
        }
      }

      if (middle)
      {
        int spriteX =
            seg->x;

        draw_object(
            middle,
            spriteX,
            seg->y);

        if (i == COLLISION_INDEX && spriteX > width / 2 - 8 && spriteX < width / 2 + 8)
        {
          colission = middle;
          colissionMask = 0b00110011;
        }
      }

      if (left)
      {
        int spriteX =
            seg->x -
            (seg->scale *
             roadW *
             width * 0.33) /
                2;

        draw_object(
            left,
            spriteX,
            seg->y);

        if (i == COLLISION_INDEX && spriteX > width / 2 - 8 && spriteX < width / 2 + 8)
        {
          colission = left;
          colissionMask = 0b00001111;
        }
      }
    }
  }
}

void game_reset()
{
  reset_road();

  colission = 0;
  isGameOver = 0;
  isDriving = 1;
  targetLane = 1;
  fuel = MAX_FUEL;
  cameraX = 0;
  notDrivingTimer = 0;
  score = 0;
}

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup()
{
  // initiate arduboy instance
  arduboy.begin();
  width = arduboy.width();
  height = arduboy.height();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);

  game_reset();

  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
#endif
  // tunes.playScore(musicScore);
}

void game_render()
{
  colission = 0;
  colissionMask = 0xFF;

  // render the background
  draw_background();

  // render the road
  render_road();

  // render the player
  arduboy.fillRect(width / 2 - 8, height - 2 - 16, 16, 16, 0);
  arduboy.drawBitmap(width / 2 - 8, height - 2 - 16, player, 16, 16);

  // draw the fuel bar
  draw_fuel((float)fuel / MAX_FUEL);

  // draw the score
  char scoreStr[16];
  sprintf(scoreStr, "%d", score);
  char scoreWidth = (arduboy.getCharacterWidth() + arduboy.getCharacterSpacing()) * strlen(scoreStr);

  arduboy.fillRect(width - scoreWidth, 0, scoreWidth, arduboy.getCharacterHeight());
  arduboy.setCursor(width - scoreWidth, 0);
  arduboy.print(scoreStr);

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}

void game_update()
{
  if (colission == OBJECT_BARREL)
  {
    // TODO: crash
    isDriving = false;
  }
  else if (colission == OBJECT_GAS)
  {
    fuel = min(MAX_FUEL, fuel + 100);
    segment *seg = get_segment(COLLISION_INDEX);
    seg->objects &= colissionMask;
  }
  else if (colission == OBJECT_BEAR)
  {
    score += 100;
    segment *seg = get_segment(COLLISION_INDEX);
    seg->objects &= colissionMask;
  }

  add_next_track();

  if (isDriving)
  {
    advance_track(1);

    fuel -= FUEL_USAGE;
    if (fuel < 0)
    {
      fuel = 0;
      isDriving = 0;
    }
  }

  if (!isDriving)
  {
    notDrivingTimer++;

    if (notDrivingTimer > 30)
    {
      isGameOver = 1;
    }
  }

  int targetX = (targetLane - 1) * 1000;

  if (isDriving)
  {
    if (targetX < cameraX)
    {
      cameraX -= 250;
    }
    else if (targetX > cameraX)
    {
      cameraX += 250;
    }
    else
    {
      if (arduboy.pressed(LEFT_BUTTON))
      {
        if (targetLane > 0)
        {
          targetLane--;
        }
      }
      if (arduboy.pressed(RIGHT_BUTTON))
      {
        if (targetLane < 2)
        {
          targetLane++;
        }
      }
    }
  }
}

void game()
{
  game_render();
  game_update();
}

void game_over()
{
  Sprites::drawSelfMasked(width - 48, height - 48, bearLogo, 0);

  arduboy.setCursor(20, 10);
  arduboy.print("GAME OVER");

  arduboy.setCursor(0, 40);
  arduboy.println("press A to");
  arduboy.println("play again.");

  if (arduboy.pressed(A_BUTTON))
  {
    game_reset();
  }

  arduboy.display();
}

void game_title()
{
  Sprites::drawSelfMasked(0, 0, title, 0);

  if (arduboy.pressed(A_BUTTON))
  {
    isGameStarted = 1;
  }

  arduboy.display();
}

// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  arduboy.pollButtons();

  // first we clear our screen to black
  arduboy.clear();

  if (!isGameStarted)
  {
    game_title();
  }
  else if (!isGameOver)
  {
    game();
  }
  else
  {
    game_over();
  }
}
