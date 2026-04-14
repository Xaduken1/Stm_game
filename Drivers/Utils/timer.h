#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

extern volatile uint8_t g_move_tick_flag;

void Timer_Start(void);
void Timer_Stop(void);
void Timer_SetPeriod(uint16_t arr);
void Timer_OnElapsedIRQ(void);

#endif
