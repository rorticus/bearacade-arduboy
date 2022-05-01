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
#include "mountains.h"

// make an instance of arduboy used for many functions
Arduboy2 arduboy;

#define DRAW_DISTANCE 50
#define MAX_SEGMENTS 128

unsigned char solid_pattern[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char checkered_pattern[] = {
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
};
unsigned char v_stripes_pattern[] = {
  0b11111111,
  0b00000000,
  0b11111111,
  0b00000000,
  0b11111111,
  0b00000000,
  0b11111111,
  0b00000000,
};

typedef struct _segment {
  int curve;
  int y;
  int z;
} segment;

segment segments[MAX_SEGMENTS];
unsigned char segmentStart = 0;
unsigned char segmentEnd = MAX_SEGMENTS - 1;

int roadW = 2300;
int segL = 256;
float camD = 0.84;
int height;
int width;
int cameraZ = 1;
int cameraX = 0;

void reset_road() {
  for (int i = 0; i < MAX_SEGMENTS; i++) {
    segments[i].z = i * segL;
    segments[i].curve = 4;
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

void draw_segment(int x1, int y1, int w1, int x2, int y2, int w2, int z) {

  float Wd = (float)((w2 - w1) / 2) / (float)(y1 - y2);
  float Xd = (float)(x2 - x1) / (float)(y1 - y2);

  float x = x1;
  float w = w1 / 2;
  
  int index = z >> 8;

  char drawLanes = index % 8 < 4;

  char *grassPattern = index % 20 < 10 ? solid_pattern : checkered_pattern;

  
  for(int y = y1; y >= y2; y--) {

    int rumbleWidth = (float)w * 0.15;
    int lineWidth = rumbleWidth;
    int rumbleLeft = x - w - rumbleWidth;
    int rumbleRight = x + w;

    // rumble strips
//    draw_patterned_hline(rumbleLeft, y, rumbleWidth, solid_pattern);
//    draw_patterned_hline(rumbleRight, y, rumbleWidth, solid_pattern);

    // grass
    draw_patterned_hline(0, y, x - w, grassPattern);
    draw_patterned_hline(x + w, y, width - x - w, grassPattern);

    // lane markers
    if(drawLanes) {
      draw_patterned_hline(x - lineWidth / 2, y, lineWidth, solid_pattern);
    }
    
    x += Xd;
    w += Wd;
  }
  

//   arduboy.drawLine(x1 - w1 / 2, y1, x1 + w1 / 2, y1);
//   arduboy.drawLine(x1 + w1 / 2, y1, x2 + w2 / 2, y2);
//   arduboy.drawLine(x2 + w2 / 2, y2, x2 - w2 / 2, y2);
//   arduboy.drawLine(x2 - w2 / 2, y2, x1 - w1 / 2, y1);
}

void draw_patterned_hline(int x, int y, int w, unsigned char *pattern) {
  unsigned char p = pattern[y & 7];

  if(y < 0 || y >= height || w <= 0) {
    return;
  }

  for(unsigned char i = max(0, x); i < x + w && i < width; i++) {
    unsigned char m = 1 << (i & 7);

    if(p & m) {
      arduboy.drawPixel(i, y);
    }
  }
}

void render_road() {
  int lastX, lastY, lastW;
  int baseSegment = cameraZ / segL;

  float baseX = 0, dx = 0;

  for(int i = 0; i < DRAW_DISTANCE; i++) {
    segment *seg = &segments[(baseSegment + i) % MAX_SEGMENTS];

    int x = 0, y = 0, w = 0;
    project(0, 0, seg->z, (float)cameraX - baseX, 1500, cameraZ, &x, &y, &w);
//
//    if(x < 0 || y < 0) {
//      char str[64];
//      sprintf(str, "%d, %d, %d", cameraX, x, y);
//      arduboy.println(str);
//      return;
//    }

    baseX += dx;
    dx += seg->curve;
    
    if(i > 1) {
      draw_segment(lastX, lastY, lastW, x, y, w, seg->z);
    }

    lastX = x;
    lastY = y;
    lastW = w;
  }
}

void generate_more_track() {
  char toGenerate = 0;
  while(segmentStart != segmentEnd) {
    if(segments[segmentStart].z < cameraZ) {
      segmentStart = (segmentStart + 1) % MAX_SEGMENTS;
      
      toGenerate++;
    } else {
      break;
    }
  }

  int lastZ = segments[segmentEnd].z;
  
  while(toGenerate > 0) {
    segmentEnd = (segmentEnd + 1) % MAX_SEGMENTS;
    segments[segmentEnd].z = lastZ + segL;
    segments[segmentEnd].curve = 0;
    
    lastZ += segL;
    toGenerate--;
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
  arduboy.drawRect(0, 0, width, height);

  // render the road
   render_road();

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();

  if(arduboy.pressed(UP_BUTTON)) {
    cameraZ += segL;
  }

  if(arduboy.pressed(DOWN_BUTTON)) {
    cameraZ -= segL;
  }

  if(arduboy.pressed(LEFT_BUTTON)) {
    cameraX -= 200;
  }
  if(arduboy.pressed(RIGHT_BUTTON)) {
    cameraX += 200;
  }

  generate_more_track();
}
