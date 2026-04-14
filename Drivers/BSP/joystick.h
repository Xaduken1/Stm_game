#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdint.h>

typedef enum
{
    JOY_NONE = 0,
    JOY_UP,
    JOY_DOWN,
    JOY_LEFT,
    JOY_RIGHT
} JoyDirection;

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t x_center;
    uint16_t y_center;
    uint8_t calibrated;
} JoystickData;

extern volatile uint16_t g_adc_buffer[2];
extern JoystickData g_joystick;

void Joystick_Init(void);
void Joystick_Calibrate(void);
JoyDirection Joystick_GetDirection(void);
uint8_t Joystick_ButtonPressed(void);
uint8_t Joystick_ButtonClicked(void);

#endif
