#include <Arduboy2.h>

extern Arduboy2 arduboy;

extern int height;
extern int width;

extern const unsigned char solid_pattern[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
extern const unsigned char checkered_pattern[] = {
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
};
extern const unsigned char v_stripes_pattern[] = {
  0b11111111,
  0b00000000,
  0b11111111,
  0b00000000,
  0b11111111,
  0b00000000,
  0b11111111,
  0b00000000,
};

void draw_patterned_hline(int x, int y, int w, const unsigned char *pattern) {
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
