#ifndef _DRAWING_H_
#define _DRAWING_H_

extern const unsigned char *solid_pattern;
extern const unsigned char *checkered_pattern;
extern const unsigned char *v_stripes_pattern;

void draw_patterned_hline(int x, int y, int w, const unsigned char *pattern);

#endif