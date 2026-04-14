#include "joystick.h"
#include "adc.h"
#include "main.h"

volatile uint16_t g_adc_buffer[2] = {0, 0};
JoystickData g_joystick = {0};

#define JOY_DEADZONE 200U

void Joystick_Init(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)g_adc_buffer, 2);
    HAL_Delay(200);
    Joystick_Calibrate();
}

void Joystick_Calibrate(void)
{
    uint32_t sum_x = 0;
    uint32_t sum_y = 0;

    for (int i = 0; i < 64; i++)
    {
        HAL_Delay(2);
        sum_x += g_adc_buffer[0];
        sum_y += g_adc_buffer[1];
    }

    g_joystick.x_center = sum_x / 64;
    g_joystick.y_center = sum_y / 64;
    g_joystick.calibrated = 1;
}

JoyDirection Joystick_GetDirection(void)
{
    int32_t dx = (int32_t)g_adc_buffer[0] - (int32_t)g_joystick.x_center;
    int32_t dy = (int32_t)g_adc_buffer[1] - (int32_t)g_joystick.y_center;

    const int32_t deadzone = 500;

    if ((dx > -deadzone && dx < deadzone) &&
        (dy > -deadzone && dy < deadzone))
    {
        return JOY_NONE;
    }

    if ((dx > 0 ? dx : -dx) > (dy > 0 ? dy : -dy))
    {
        return (dx > 0) ? JOY_RIGHT : JOY_LEFT;
    }
    else
    {
        return (dy > 0) ? JOY_DOWN : JOY_UP;
    }
}

uint8_t Joystick_ButtonPressed(void)
{
    return (HAL_GPIO_ReadPin(JOY_SW_GPIO_Port, JOY_SW_Pin) == GPIO_PIN_RESET) ? 1 : 0;
}

uint8_t Joystick_ButtonClicked(void)
{
    static uint8_t prev = 0;
    uint8_t now = Joystick_ButtonPressed();

    if (now && !prev)
    {
        prev = now;
        return 1;
    }

    prev = now;
    return 0;
}
