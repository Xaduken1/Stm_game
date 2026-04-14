#include "random.h"

static uint32_t s_rand = 1;

void Random_Init(uint32_t seed)
{
    s_rand = seed ? seed : 1;
}

uint32_t Random_Next(void)
{
    s_rand = s_rand * 1664525UL + 1013904223UL;
    return s_rand;
}

uint32_t Random_Range(uint32_t min, uint32_t max)
{
    if (max <= min)
        return min;

    return min + (Random_Next() % (max - min + 1));
}
