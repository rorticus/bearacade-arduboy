#ifndef _TRACK_H_
#define _TRACK_H_

#define MAX_SEGMENTS 128

typedef struct _segment {
  char curve;
  unsigned char index;
} segment;

unsigned char track_length();
void add_segment(char curve);
void add_road(unsigned char enter, unsigned char hold, unsigned char leave, char curve);
segment *get_segment(unsigned char index);
void advance_track(unsigned char count);
void add_next_track();

#endif
