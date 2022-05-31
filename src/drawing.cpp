#include <Arduboy2.h>
#include "sprites.h"
#include "track.h"

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
    int destX,
    int destY)
{
  if (destY - 16 > 64 || destY < 0 || destX < 0 || destX > 128)
  {
    return;
  }

  Sprites::drawExternalMask(destX - 4, destY - 16, treeSmall, treeSmallMask, 0, 0);
}

void draw_object(
    unsigned char type,
    int destX,
    int destY)
{
  if (destY - 8 > 64 || destY < 0 || destX < 0 || destX > 128)
  {
    return;
  }

  if (type == OBJECT_BARREL)
  {
    Sprites::drawExternalMask(destX - 3, destY - 4, drum, drumMask, 0, 0);
  }
  else if (type == OBJECT_GAS) {
    Sprites::drawExternalMask(destX - 3, destY - 4, gasCan, gasCanMask, 0, 0);
  }
}

void draw_background()
{
  arduboy.clear();
  arduboy.drawBitmap(0, 2, mountains, 128, 32);
}

void draw_fuel(float percentage) {
  char w = 50;
  char h = 4;
  char left = 2;
  char top = 2;
  char fillWidth = w * percentage;

  arduboy.fillRect(left, top, w, h, 0);
  arduboy.drawRect(left, top, w, h);

  draw_patterned_hline(left + 1, top + 1, fillWidth, checkered_pattern);
  draw_patterned_hline(left + 1, top + 2, fillWidth, checkered_pattern);
  
  arduboy.drawFastVLine(left + fillWidth, top, h);
}