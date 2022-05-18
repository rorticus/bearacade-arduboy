#ifndef _TRACK_H_
#define _TRACK_H_

#define MAX_SEGMENTS 64

#define SPRITE_NONE 0
#define SPRITE_TREE 1
#define SPRITE_ROCK 2
#define SPRITE_MAX  3

#define OBJECT_NONE   0
#define OBJECT_BEAR   1
#define OBJECT_BARREL 2
#define OBJECT_GAS    3

#define OBJECT_LEFT(x)   ((x) >> 4)
#define OBJECT_MIDDLE(x) ((x) >> 2 & 0b11)
#define OBJECT_RIGHT(x)  ((x) & 0b11)

typedef struct _segment {
  char curve;
  unsigned char index;
  unsigned char sprite;
  unsigned char x;
  unsigned char y;
  float scale;
  unsigned char objects;
} segment;

unsigned char track_length();
void add_segment(char curve);
void add_road(unsigned char enter, unsigned char hold, unsigned char leave, char curve);
segment *get_segment(unsigned char index);
void advance_track(unsigned char count);
void add_next_track();
void reset_road();

#endif
