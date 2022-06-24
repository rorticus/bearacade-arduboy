#include <Arduboy2.h>

// 128x32
extern const uint8_t PROGMEM mountains[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x78, 0xee, 0xf2, 0xfd, 0xff, 0xf2, 0x64, 0xe8, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0xf0, 0xf0, 0x50, 0x70, 0xb0, 0xb0, 0xb0, 0x30, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xa0, 0xa0, 0xe0, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x78, 0xec, 0xf7, 0xff, 0xfd, 0xff, 0xcf, 0xff, 0xff, 0x9f, 0xff, 0xfd, 0xff, 0xff, 0xfb, 0xff, 0xf8, 0xc0, 0x00, 0x80, 0xc0, 0xf0, 0x98, 0xfc, 0xff, 0xf9, 0xfc, 0xff, 0xff, 0x8e, 0x3e, 0xfc, 0xd0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0x7f, 0xf7, 0xfe, 0xff, 0xf8, 0xfe, 0x5f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xab, 0x5c, 0x60, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xc0, 0xe0, 0xb0, 0xe8, 0xe4, 0x6f, 0xe9, 0xff, 0xfa, 0xfe, 0xff, 0xcf, 0xfb, 0xde, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xbc, 0xf0, 0xc0, 0xb0, 0x5a, 0x7b, 0xec, 0xc7, 0xd5, 0x2d, 0x9f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x8f, 0xe2, 0xfc, 0xf1, 0xff, 0xbf, 0xf7, 0xf3, 0xf9, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0xfc, 0xf9, 0xff, 0xfe, 0xfc, 0xf9, 0xfa, 0xf4, 0x88, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0xe0, 0xb0, 0x90, 0xf8, 0xf8, 0xec, 0xe6, 0x77, 0xff, 0x7e, 0x94, 0xde, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xec, 0xef, 0x73, 0xff, 0x7f, 0x7f, 0xff, 0xdf, 0xbf, 0xfd, 0xf8, 0xf7, 0xe1, 0xcb, 0x22, 0xa8, 0x70, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xc0, 0xff, 0x23, 0x5c, 0x0f, 0x0f, 0x24, 0x03, 0x07, 0x07, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xcf, 0x3f, 0xf8, 0xe3, 0x8f, 0x3e, 0x5c, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xc3, 0xfc, 0xff, 0xe3, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0x7f, 0xff, 0x83, 0xf3, 0x27, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xdf, 0xff, 0xff, 0xff, 0xce, 0x3f, 0xfe, 0xe4, 0x88, 0x70, 0x20, 0xa0, 0xe0, 0xe8, 0xe0, 0xf6, 0xff, 0xfe, 0xc7, 0x73, 0xfb, 0xf9, 0xfd, 0x3f, 0xff, 0xff, 0xff, 0xe1, 0xfd, 0xfb, 0xff, 0xeb, 0xdf, 0xea, 0xe5, 0xbf, 0xff, 0xfb, 0xd7, 0x7f, 0x8d, 0xce, 0xdf, 0xcd, 0xfb, 0x5f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xfc, 0xf1, 0xc5, 0x0f, 0x5e, 0xf8, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 
};

extern const uint8_t PROGMEM drum[] = {
    16, 16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x92, 0xa4, 0xa4, 0xa4, 0x92, 0x7f, 0x00, 0x00, 0x00, 0x00
    
};

extern const uint8_t PROGMEM drumMask[] = {
    0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00
    
};


extern const uint8_t PROGMEM gas[] = {
    8, 9,
    0x00, 0xf8, 0x08, 0x68, 0x68, 0x0e, 0xf6, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
    
};

extern const uint8_t PROGMEM gasMask[] = {
    0xfc, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
    
};


extern const uint8_t PROGMEM treeSmall[] = {
16, 16,
0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x78, 0x7e, 0x7e, 0x78, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0c, 0x1d, 0x1b, 0x1b, 0x5b, 0x5b, 0x1b, 0x1b, 0x1d, 0x0c, 0x00, 0x00, 0x00, 
};

extern const uint8_t PROGMEM treeSmallMask[] = {
0x00, 0x00, 0x00, 0x80, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x1e, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x1e, 0x00, 0x00, 
};

// 16x16
extern const uint8_t PROGMEM player[] = {
    0xc0, 0xfe, 0x02, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x02, 0xfe, 0xc0, 
    0x00, 0xff, 0xe8, 0xea, 0x2a, 0x2a, 0x3e, 0x36, 0x36, 0x3e, 0x2a, 0x2a, 0xea, 0xe8, 0xff, 0x00    
};

extern const uint8_t PROGMEM bear[] = {
    16, 16,
    0x00, 0x00, 0x00, 0x0c, 0xf4, 0xf8, 0x5c, 0x7c, 0x5c, 0xf8, 0xf4, 0x0c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xcf, 0x1e, 0xfd, 0x79, 0x7a, 0x79, 0xfd, 0x1e, 0xcf, 0x7f, 0x00, 0x00, 0x00
    
};

extern const uint8_t PROGMEM bearMask[] = {
    0x00, 0x80, 0x9e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x9e, 0x80, 0x00, 0x00, 
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00
    
};

extern const uint8_t PROGMEM bearSmall[] = {
    16, 16,
    0x00, 0x00, 0x00, 0x00, 0x20, 0xc0, 0x60, 0xe0, 0x60, 0xc0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7c, 0x9c, 0xfb, 0x71, 0x75, 0x71, 0xfb, 0x9c, 0x7c, 0x00, 0x00, 0x00, 0x00
    
};

extern const uint8_t PROGMEM bearSmallMask[] = {
    0x00, 0x00, 0x00, 0x70, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x70, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x00, 0x00, 0x00
    
};

extern const uint8_t PROGMEM title[] = {
    128, 64,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x24, 0x24, 0x24, 0x24, 0xfc, 
    0x98, 0xfc, 0xfc, 0x24, 0x24, 0x24, 0x24, 0x04, 0x04, 0x00, 0xf0, 0xf8, 0x88, 0x84, 0x84, 0x8c, 
    0xf8, 0xf0, 0x00, 0xfc, 0xfc, 0x84, 0x84, 0x84, 0xe4, 0x7c, 0x70, 0x00, 0xf0, 0xf8, 0x88, 0x84, 
    0x84, 0x8c, 0xf8, 0xf0, 0xf0, 0xf8, 0x0c, 0x04, 0x04, 0x04, 0x0c, 0x08, 0x00, 0xf0, 0xf8, 0x88, 
    0x84, 0x84, 0x8c, 0xf8, 0xf0, 0x00, 0xfc, 0xfc, 0x04, 0x04, 0x04, 0x0c, 0xf8, 0xf0, 0x00, 0xfc, 
    0xfc, 0x24, 0x24, 0x24, 0x24, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x23, 0x23, 0x22, 0x22, 0x22, 0x22, 0x23, 
    0x21, 0x23, 0x23, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x20, 0x23, 0x23, 0x20, 0x20, 0x20, 0x20, 
    0x23, 0x23, 0x20, 0x23, 0x23, 0x20, 0x20, 0x21, 0x23, 0x23, 0x22, 0x20, 0x23, 0x23, 0x20, 0x20, 
    0x20, 0x20, 0x23, 0x23, 0x20, 0x21, 0x23, 0x22, 0x22, 0x22, 0x23, 0x21, 0x20, 0x23, 0x23, 0x20, 
    0x20, 0x20, 0x20, 0x23, 0x23, 0x20, 0x23, 0x23, 0x22, 0x22, 0x22, 0x23, 0x21, 0x20, 0x20, 0x23, 
    0x23, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7c, 0x10, 0x7c, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x04, 0x7c, 0x04, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x78, 0x14, 0x78, 0x00, 0x48, 0x54, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 
    0x08, 0x7c, 0x00, 0x78, 0x14, 0x78, 0x00, 0x7c, 0x04, 0x78, 0x00, 0x1c, 0x70, 0x1c, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7c, 0x54, 0x28, 0x00, 0x7c, 0x54, 0x54, 0x00, 0x78, 0x14, 0x78, 0x00, 0x7c, 
    0x14, 0x68, 0x00, 0x48, 0x54, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x14, 0x78, 0x00, 0x48, 
    0x54, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x70, 0x1c, 0x00, 0x38, 0x44, 0x38, 0x00, 0x7c, 
    0x40, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x28, 0x00, 0x78, 0x14, 0x78, 0x00, 0x7c, 
    0x04, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3e, 0x10, 0x3e, 0x00, 0x3e, 0x08, 0x3e, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x3e, 
    0x20, 0x20, 0x00, 0x3e, 0x2a, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x0a, 0x3c, 0x00, 0x1e, 
    0x30, 0x1e, 0x00, 0x1c, 0x22, 0x1c, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x3e, 0x22, 0x1c, 0x00, 0x00, 
    0x3e, 0x00, 0x00, 0x3e, 0x02, 0x3c, 0x00, 0x1c, 0x22, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 
    0x2a, 0x14, 0x00, 0x3c, 0x0a, 0x3c, 0x00, 0x3e, 0x0a, 0x34, 0x00, 0x3e, 0x0a, 0x34, 0x00, 0x3e, 
    0x2a, 0x2a, 0x00, 0x3e, 0x20, 0x20, 0x00, 0x24, 0x2a, 0x12, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1c, 0x22, 0x14, 0x00, 0x1c, 0x22, 0x1c, 0x00, 0x3e, 0x20, 0x20, 0x00, 0x3e, 
    0x20, 0x20, 0x00, 0x3e, 0x2a, 0x2a, 0x00, 0x1c, 0x22, 0x14, 0x00, 0x02, 0x3e, 0x02, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0e, 0x11, 0x19, 0x00, 0x1e, 0x05, 0x1e, 0x00, 0x12, 0x15, 0x09, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0e, 0x11, 0x0a, 0x00, 0x1e, 0x05, 0x1e, 0x00, 0x1f, 0x01, 0x1e, 0x00, 0x12, 
    0x15, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x01, 0x00, 0x0e, 0x11, 0x0e, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x1f, 0x01, 0x1e, 0x00, 0x0e, 0x11, 0x0a, 0x00, 0x1f, 
    0x05, 0x1a, 0x00, 0x1f, 0x15, 0x15, 0x00, 0x1e, 0x05, 0x1e, 0x00, 0x12, 0x15, 0x09, 0x00, 0x1f, 
    0x15, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x05, 0x05, 0x00, 0x1f, 0x10, 0x1f, 0x00, 0x1f, 
    0x15, 0x15, 0x00, 0x1f, 0x10, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 
    0x00, 0x00, 0x18, 0xe8, 0xf0, 0xb8, 0xf8, 0xb8, 0xf0, 0xe8, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x50, 0x50, 0x20, 0x00, 0xf0, 0x50, 
    0xd0, 0x20, 0x00, 0xf0, 0x50, 0x50, 0x10, 0x00, 0x20, 0x50, 0x50, 0x90, 0x00, 0x20, 0x50, 0x50, 
    0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x50, 0x50, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x10, 0xf0, 0x10, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x20, 0x50, 0x50, 0x90, 0x00, 0x10, 0xf0, 0x10, 0x00, 0x00, 0xe0, 0x50, 0x50, 0xe0, 0x00, 0xf0, 
    0x50, 0xd0, 0x20, 0x00, 0x10, 0xf0, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xe8, 0xf0, 0xb8, 0xf8, 0xb8, 0xf0, 0xe8, 0x18, 0x00, 0x00, 
    0x00, 0xfe, 0x9e, 0x3d, 0xfb, 0xf2, 0xf4, 0xf2, 0xfb, 0x3d, 0x9e, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
    0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xfe, 0x9e, 0x3d, 0xfb, 0xf2, 0xf4, 0xf2, 0xfb, 0x3d, 0x9e, 0xfe, 0x00    
};


extern const uint8_t PROGMEM gameOver[] = {
    128, 64,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x84, 0xc4, 0x64, 0x24, 0x24, 
    0x24, 0x24, 0x24, 0x84, 0xc4, 0x44, 0x24, 0x24, 0x64, 0xc4, 0x84, 0x04, 0xe4, 0xe4, 0xc4, 0x84, 
    0x84, 0xc4, 0xe4, 0xe4, 0x04, 0xe4, 0xe4, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x04, 0x04, 0x04, 
    0xc4, 0xe4, 0x24, 0x24, 0x24, 0x24, 0xe4, 0xc4, 0x04, 0xe4, 0xe4, 0x04, 0x04, 0x04, 0x04, 0xe4, 
    0xe4, 0xe4, 0xe4, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x04, 0xe4, 0xe4, 0x24, 0x24, 0x24, 0x24, 
    0xe4, 0x84, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x87, 0x9f, 0x98, 0x90, 0x90, 
    0x92, 0x9e, 0x9e, 0x9f, 0x9f, 0x84, 0x84, 0x84, 0x84, 0x9f, 0x9f, 0x80, 0x9f, 0x9f, 0x81, 0x83, 
    0x83, 0x81, 0x9f, 0x9f, 0x80, 0x9f, 0x9f, 0x91, 0x91, 0x91, 0x91, 0x90, 0x90, 0x80, 0x80, 0x80, 
    0x8f, 0x9f, 0x90, 0x90, 0x90, 0x90, 0x9f, 0x8f, 0x80, 0x87, 0x87, 0x8f, 0x9c, 0x9c, 0x8e, 0x87, 
    0x87, 0x9f, 0x9f, 0x91, 0x91, 0x91, 0x91, 0x90, 0x90, 0x80, 0x9f, 0x9f, 0x84, 0x84, 0x8c, 0x9f, 
    0x9b, 0x93, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7c, 0xfe, 0xfe, 0x7e, 0x3e, 0x1c, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
    0x08, 0x08, 0x08, 0x08, 0x08, 0x1c, 0x3e, 0x7e, 0xfe, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xc0, 0x38, 0x06, 0x01, 0x80, 0xc0, 0xe0, 0x90, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xe0, 0x90, 0xe0, 0xc0, 0x80, 0x01, 0x06, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3e, 0x0a, 0x0a, 0x04, 0x00, 0x3e, 0x0a, 0x1a, 0x24, 0x00, 0x3e, 0x2a, 0x2a, 0x22, 
    0x00, 0x24, 0x2a, 0x2a, 0x12, 0x00, 0x24, 0x2a, 0x2a, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x3c, 0x0a, 0x0a, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x07, 0x0f, 0x8f, 0x03, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xfc, 0x03, 0x03, 0x8f, 0x0f, 0x07, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x02, 0x3e, 0x02, 0x00, 0x00, 0x1c, 0x22, 0x22, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x02, 0x3e, 0x02, 0x00, 0x00, 0x3e, 0x0a, 0x1a, 0x24, 0x00, 0x06, 0x38, 0x06, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x0a, 0x0a, 0x3c, 0x00, 0x1c, 0x22, 0x2a, 0x18, 0x00, 0x3c, 
    0x0a, 0x0a, 0x3c, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x04, 0x08, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    0x40, 0x40, 0x20, 0x23, 0x2c, 0x10, 0x10, 0x10, 0x11, 0x1e, 0x20, 0x40, 0x43, 0x27, 0x3f, 0x3f, 
    0x27, 0x43, 0x40, 0x20, 0x1e, 0x11, 0x10, 0x10, 0x10, 0x2c, 0x23, 0x20, 0x40, 0x40, 0x80, 0x00  
};

