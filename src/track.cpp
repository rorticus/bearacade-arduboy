#include "track.h"
#include <stdlib.h>

#define OBJECT_FREQ 6

segment segments[MAX_SEGMENTS];
unsigned char segmentHead = 0;
unsigned char segmentTail = 0;

// the last added track index
unsigned char lastIndex = 0;
unsigned char segFreq = 0;

#define ROAD_STRAIGHT 0
#define ROAD_LEFT_CURVE_SOFT 1
#define ROAD_RIGHT_CURVE_SOFT 2
#define ROAD_LEFT_CURVE_HARD 3
#define ROAD_RIGHT_CURVE_HARD 4
#define MAX_ROAD_TYPES 5

#define NO_BARRELS 0
#define BARREL_RIGHT 1
#define BARREL_MIDDLE 2
#define BARREL_MIDDLE_RIGHT 3
#define BARREL_LEFT 4
#define BARREL_LEFT_RIGHT 5
#define BARREL_LEFT_MIDDLE 6

#define NUM_OBJ_CASES 7
#define NUM_OBJ_CHANCES 10

unsigned char lastObjects = 0;
const unsigned char objectDecider[NUM_OBJ_CASES][NUM_OBJ_CHANCES] = {
    /* 0 000 */ {0, 0, 0, 0, 0, BARREL_LEFT, BARREL_LEFT_MIDDLE, BARREL_MIDDLE, BARREL_RIGHT, BARREL_MIDDLE_RIGHT},
    /* 1 001 */ {0, 0, 0, 0, 0, BARREL_LEFT, BARREL_RIGHT, BARREL_MIDDLE_RIGHT, BARREL_MIDDLE, 0},
    /* 2 010 */ {0, 0, 0, 0, 0, BARREL_RIGHT, BARREL_LEFT, BARREL_MIDDLE_RIGHT, BARREL_LEFT_MIDDLE, BARREL_MIDDLE},
    /* 3 011 */ {0, 0, 0, 0, 0, BARREL_MIDDLE, BARREL_MIDDLE_RIGHT, BARREL_RIGHT, 0, 0},
    /* 4 100 */ {0, 0, 0, 0, 0, BARREL_LEFT, BARREL_MIDDLE, BARREL_LEFT_MIDDLE, BARREL_RIGHT, 0},
    /* 5 101 */ {0, 0, 0, 0, 0, BARREL_LEFT, BARREL_RIGHT, 0, 0, 0},
    /* 6 110 */ {0, 0, 0, 0, 0, BARREL_LEFT, BARREL_LEFT_MIDDLE, BARREL_MIDDLE, 0, 0}};

void add_segment(char curve)
{
  unsigned char sprite = 0;
  unsigned char obj = 0;

  if (rand() % 100 < 10)
  {
    sprite = SPRITE_TREE;
  }

  if (rand() % 100 < 10)
  {
    sprite |= SPRITE_TREE << 4;
  }

  segFreq++;
  if (segFreq > OBJECT_FREQ)
  {
    segFreq = 0;

    unsigned char barrels = objectDecider[lastObjects][rand() % NUM_OBJ_CHANCES];
    lastObjects = obj;

    if ((barrels & 1) == 1)
    {
      obj |= OBJECT_BARREL;
    }

    if ((barrels & 2) == 2)
    {
      obj |= OBJECT_BARREL << 2;
    }

    if ((barrels & 4) == 4)
    {
      obj |= OBJECT_BARREL << 4;
    }

    char blankLeft = OBJECT_LEFT(obj) == OBJECT_NONE;
    char blankMiddle = OBJECT_MIDDLE(obj) == OBJECT_NONE;
    char blankRight = OBJECT_RIGHT(obj) == OBJECT_NONE;

    if (blankLeft)
    {
      int n = rand() % 100;

      if (n < 10)
      {
        obj |= OBJECT_GAS << 4;
      }
      else if (n < 20)
      {
        obj |= OBJECT_BEAR << 4;
      }
    }

    if (blankMiddle)
    {
      int n = rand() % 1000;

      if (n < 10)
      {
        obj |= OBJECT_GAS << 2;
      }
      else if (n < 20)
      {
        obj |= OBJECT_BEAR << 2;
      }
    }

    if (blankRight)
    {
      int n = rand() % 1000;

      if (n < 10)
      {
        obj |= OBJECT_GAS;
      }
      else if (n < 20)
      {
        obj |= OBJECT_BEAR;
      }
    }
  }

  segments[segmentTail].curve = curve;
  segments[segmentTail].index = lastIndex;
  segments[segmentTail].sprite = sprite;
  segments[segmentTail].objects = obj;

  lastIndex = (lastIndex + 1) % 20;
  segmentTail = (segmentTail + 1) % MAX_SEGMENTS;

  if (segmentTail == segmentHead)
  {
    segmentHead = (segmentHead + 1) % MAX_SEGMENTS;
  }
}

void add_road(unsigned char enter, unsigned char hold, unsigned char leave, char curve)
{
  for (unsigned char n = 0; n < enter; n++)
  {
    add_segment(0);
  }

  for (unsigned char n = 0; n < hold; n++)
  {
    add_segment(curve);
  }

  for (unsigned char n = 0; n < leave; n++)
  {
    add_segment(0);
  }
}

unsigned char track_length()
{
  /* H--T
   * 0123456789
   */
  if (segmentHead < segmentTail)
  {
    return segmentTail - segmentHead;
  }

  /* -T     H--
   * 0123456789
   */
  return MAX_SEGMENTS - segmentHead + segmentTail;
}

segment *get_segment(unsigned char index)
{
  return &segments[(segmentHead + index) % MAX_SEGMENTS];
}

void advance_track(unsigned char count)
{
  segmentHead = (segmentHead + count) % MAX_SEGMENTS;
}

void add_next_track()
{
  char tile = rand() % MAX_ROAD_TYPES;

  if (track_length() > MAX_SEGMENTS - 33)
  {
    return;
  }

  switch (tile)
  {
  case ROAD_STRAIGHT:
    add_road(0, 32, 0, 0);
    break;
  case ROAD_LEFT_CURVE_SOFT:
    add_road(0, 32, 0, -2);
    break;
  case ROAD_RIGHT_CURVE_SOFT:
    add_road(0, 32, 0, 2);
    break;
  case ROAD_RIGHT_CURVE_HARD:
    add_road(0, 32, 0, 8);
    break;
  case ROAD_LEFT_CURVE_HARD:
    add_road(0, 32, 0, -8);
    break;
  }
}

void reset_road()
{
  add_road(0, 16, 0, 0);

  while (track_length() < MAX_SEGMENTS - 33)
  {
    add_next_track();
  }
}
