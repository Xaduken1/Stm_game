#include "timer.h"
#include "tim.h"

volatile uint8_t g_move_tick_flag = 0;

void Timer_Start(void)
{
    HAL_TIM_Base_Start_IT(&htim2);
}

void Timer_Stop(void)
{
    HAL_TIM_Base_Stop_IT(&htim2);
}

void Timer_SetPeriod(uint16_t arr)
{
    __HAL_TIM_SET_AUTORELOAD(&htim2, arr);
    __HAL_TIM_SET_COUNTER(&htim2, 0);
}

void Timer_OnElapsedIRQ(void)
{
    g_move_tick_flag = 1;
}
