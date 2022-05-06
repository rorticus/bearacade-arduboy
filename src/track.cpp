#include "track.h"
#include <stdlib.h>

segment segments[MAX_SEGMENTS];
unsigned char segmentHead = 0;
unsigned char segmentTail = 0;

// the last added track index
unsigned char lastIndex = 0;

#define ROAD_STRAIGHT 0
#define ROAD_LEFT_CURVE_SOFT 1
#define ROAD_RIGHT_CURVE_SOFT 2
#define ROAD_LEFT_CURVE_HARD 3
#define ROAD_RIGHT_CURVE_HARD 4
#define MAX_ROAD_TYPES 5

void add_segment(char curve) {
  segments[segmentTail].curve = curve;
  segments[segmentTail].index = lastIndex;
  
  lastIndex = (lastIndex + 1) % 20;
  segmentTail = (segmentTail + 1) % MAX_SEGMENTS;

  if(segmentTail == segmentHead) {
    segmentHead = (segmentHead + 1) % MAX_SEGMENTS;
  }
}

void add_road(unsigned char enter, unsigned char hold, unsigned char leave, char curve) {
  for(unsigned char n = 0; n < enter; n++) {
    add_segment(0);
  }

  for(unsigned char n = 0; n < hold; n++) {
    add_segment(curve);
  }

  for(unsigned char n = 0; n < leave; n++) {
    add_segment(0);
  }
}

unsigned char track_length() {
  /* H--T
   * 0123456789
   */
  if(segmentHead < segmentTail) {
    return segmentTail - segmentHead;
  }

  /* -T     H--
   * 0123456789
   */
  return MAX_SEGMENTS - segmentHead + segmentTail;
}

segment *get_segment(unsigned char index) {
    return &segments[(segmentHead + index) % MAX_SEGMENTS];
}

void advance_track(unsigned char count) {
    segmentHead = (segmentHead + count) % MAX_SEGMENTS;
}

void add_next_track() {
  char tile = rand() % MAX_ROAD_TYPES;

  if(track_length() > MAX_SEGMENTS - 33) {
    return;
  }

  switch(tile) {
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

void reset_road() {
  add_road(0, 16, 0, 0);
  
  while(track_length() < MAX_SEGMENTS - 33) {
    add_next_track();
  }
}
