#include <Arduboy2.h>
#include "sprites.h"

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

unsigned char almost_solid_pattern[] = {
  0b10101010,
  0b11011101,
  0b10101010,
  0b01110111,
  0b10101010,
  0b11011101,
  0b10101010,
  0b01110111,
};

unsigned char star_pattern[] = {
  0b10101010,
  0b01000100,
  0b10101010,
  0b01000100,
  0b10101010,
  0b01000100,
  0b10101010,
  0b01000100,
};

unsigned char sparse_pattern[] = {
  0b00100010,
  0b00000000,
  0b10001000,
  0b00000000,
  0b00100010,
  0b00000000,
  0b10001000,
  0b00000000,
};

void draw_patterned_hline(int x, int y, int w, const unsigned char *pattern)
{
  unsigned char p = pattern[y & 7];

  if (y < 0 || y >= height || w <= 0)
  {
    return;
  }

  for (unsigned char i = max(0, x); i < x + w && i < width; i++)
  {
    unsigned char m = 1 << (i & 7);

    if (p & m)
    {
      arduboy.drawPixel(i, y);
    }
  }
}

void draw_segment(int x1, int y1, int w1, int x2, int y2, int w2, unsigned char index)
{

  float Wd = (float)((w2 - w1) / 2) / (float)(y1 - y2);
  float Xd = (float)(x2 - x1) / (float)(y1 - y2);

  float x = x1;
  float w = w1 / 2;

  char drawLanes = index % 10 < 2;

  const unsigned char *grassPattern = (index % 10) < 5 ? checkered_pattern : almost_solid_pattern;

  for (int y = y1; y >= y2; y--)
  {

    int rumbleWidth = (float)w * 0.15; // 1 / 6
    int lineWidth = (float)w * 0.1;    // 1 / 24
    int rumbleLeft = x - w - rumbleWidth;
    int rumbleRight = x + w;
    int laneOffset = w * 0.33;

    // rumble strips
    draw_patterned_hline(rumbleLeft, y, rumbleWidth, solid_pattern);
    draw_patterned_hline(rumbleRight, y, rumbleWidth, solid_pattern);

    // grass
    draw_patterned_hline(0, y, x - w, grassPattern);
    draw_patterned_hline(x + w, y, width - x - w, grassPattern);

    // lane markers
    if (drawLanes)
    {
      draw_patterned_hline(x - laneOffset - lineWidth / 2, y, lineWidth, solid_pattern);
      draw_patterned_hline(x + laneOffset - lineWidth / 2, y, lineWidth, solid_pattern);
    }

    x += Xd;
    w += Wd;
  }
}

void draw_sprite(
    unsigned char type,
    unsigned char destX,
    unsigned char destY)
{
  Sprites::drawExternalMask(destX - 4, destY - 16, treeSmall, treeSmallMask, 0, 0);
}

void draw_background() {
  arduboy.clear();
  arduboy.drawBitmap(0, 2, mountains, 128, 32);
}