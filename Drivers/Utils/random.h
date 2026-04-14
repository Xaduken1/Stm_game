#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

void Random_Init(uint32_t seed);
uint32_t Random_Next(void);
uint32_t Random_Range(uint32_t min, uint32_t max);

#endif
