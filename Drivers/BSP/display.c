#include "display.h"
#include "framebuffer.h"
#include "i2c.h"
#include <string.h>

#define OLED_ADDR (0x3C << 1)

static void OLED_Cmd(uint8_t cmd)
{
    uint8_t d[2] = {0x00, cmd};
    HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDR, d, 2, HAL_MAX_DELAY);
}

static void OLED_Data(uint8_t *buf, uint16_t len)
{
    uint8_t pkt[17];
    pkt[0] = 0x40;

    while (len)
    {
        uint8_t n = (len > 16) ? 16 : len;
        memcpy(&pkt[1], buf, n);
        HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDR, pkt, n + 1, HAL_MAX_DELAY);
        buf += n;
        len -= n;
    }
}

void Display_Clear(uint8_t color)
{
    FB_Clear(color);
}

void Display_Init(void)
{
    HAL_Delay(100);

    OLED_Cmd(0xAE);
    OLED_Cmd(0xD5); OLED_Cmd(0x80);
    OLED_Cmd(0xA8); OLED_Cmd(0x3F);
    OLED_Cmd(0xD3); OLED_Cmd(0x00);
    OLED_Cmd(0x40);
    OLED_Cmd(0x8D); OLED_Cmd(0x14); // charge pump for SSD1306
    OLED_Cmd(0x20); OLED_Cmd(0x00); // horizontal addressing mode
    OLED_Cmd(0xA1);
    OLED_Cmd(0xC8);
    OLED_Cmd(0xDA); OLED_Cmd(0x12);
    OLED_Cmd(0x81); OLED_Cmd(0xCF);
    OLED_Cmd(0xD9); OLED_Cmd(0xF1);
    OLED_Cmd(0xDB); OLED_Cmd(0x40);
    OLED_Cmd(0xA4);
    OLED_Cmd(0xA6);
    OLED_Cmd(0xAF);

    Display_Clear(0);
    Display_Update();
}

void Display_Update(void)
{
    OLED_Cmd(0x21); OLED_Cmd(0); OLED_Cmd(127); // column range
    OLED_Cmd(0x22); OLED_Cmd(0); OLED_Cmd(7);   // page range

    OLED_Data(g_framebuffer, 1024);
}
