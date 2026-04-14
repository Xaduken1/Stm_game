#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

#define FB_WIDTH    128
#define FB_HEIGHT   64
#define FB_SIZE     (FB_WIDTH * FB_HEIGHT / 8)

extern uint8_t g_framebuffer[FB_SIZE];

void FB_Clear(uint8_t color);
void FB_DrawPixel(int x, int y, uint8_t color);
void FB_DrawRect(int x, int y, int w, int h, uint8_t color);
void FB_FillRect(int x, int y, int w, int h, uint8_t color);
void FB_DrawChar6x8(int x, int y, char c, uint8_t color);
void FB_DrawString6x8(int x, int y, const char *str, uint8_t color);

#endif
