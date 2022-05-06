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
#include "drawing.h"
#include "track.h"

// make an instance of arduboy used for many functions
Arduboy2 arduboy;

#define DRAW_DISTANCE 50

int roadW = 2800;
int segL = 256;
float camD = 0.84;
int height;
int width;
int cameraX = 0;

void reset_road() {
  add_segment(0);
  add_segment(0);
  
  while(track_length() < MAX_SEGMENTS - 1) {
    add_segment(0);
  }
}

void project(
  float x, float y, float z,
  int camX, int camY, int camZ,
  int *X, int *Y, int *W
) {
  float scale = camD / (z - camZ);
  
  *X = (1 + scale*(x - camX)) * width / 2;
  *Y = (1 - scale*(y - camY)) * height / 2;
  *W = scale * roadW * width / 2;
}

void render_road() {
  int lastX, lastY, lastW;

  float baseX = 0, dx = 0;
  int z = 0;

  for(int i = 0; i < DRAW_DISTANCE; i++) {
    segment *seg = get_segment(i);

    int x = 0, y = 0, w = 0;
    project(0, 0, z, (float)cameraX - baseX, 1500, 0, &x, &y, &w);

    baseX += dx;
    dx += seg->curve;
    
    if(i > 1) {
      draw_segment(lastX, lastY, lastW, x, y, w, seg->index);
    }

    lastX = x;
    lastY = y;
    lastW = w;
    z += segL;
  }
}

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();
  width = arduboy.width();
  height = arduboy.height();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);

  reset_road();
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  arduboy.pollButtons();

  // first we clear our screen to black
  arduboy.clear();

  // render the background

  // render the road
   render_road();

   add_next_track();

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();

  if(arduboy.pressed(UP_BUTTON)) {
    advance_track(1);
  }

  if(arduboy.pressed(LEFT_BUTTON)) {
    cameraX -= 200;
  }
  if(arduboy.pressed(RIGHT_BUTTON)) {
    cameraX += 200;
  }
}
