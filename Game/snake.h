#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"

void Snake_Init(Snake *snake);
uint8_t Snake_IsOppositeDirection(JoyDirection a, JoyDirection b);
uint8_t Snake_Contains(const Snake *snake, uint8_t x, uint8_t y);
uint8_t Snake_Step(Snake *snake, Point food, uint8_t *ate_food);

#endif
