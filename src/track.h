#ifndef _TRACK_H_
#define _TRACK_H_

#define MAX_SEGMENTS 128

#define SPRITE_NONE 0
#define SPRITE_TREE 1
#define SPRITE_ROCK 2
#define SPRITE_MAX  3

typedef struct _segment {
  char curve;
  unsigned char index;
  unsigned char sprite;
  unsigned char x;
  unsigned char y;
  float scale;
} segment;

unsigned char track_length();
void add_segment(char curve);
void add_road(unsigned char enter, unsigned char hold, unsigned char leave, char curve);
segment *get_segment(unsigned char index);
void advance_track(unsigned char count);
void add_next_track();
void reset_road();

#endif
