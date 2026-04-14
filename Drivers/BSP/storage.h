#ifndef STORAGE_H
#define STORAGE_H

#include <stdint.h>

#define HIGHSCORES_COUNT 5

typedef struct
{
    uint32_t scores[HIGHSCORES_COUNT];
} HighScores;

extern uint32_t g_storage_debug_code;

uint8_t Storage_Init(void);
uint32_t Storage_LoadHighScore(void);
uint8_t Storage_SaveHighScore(uint32_t value);

uint8_t Storage_LoadHighScores(HighScores *table);
uint8_t Storage_SaveHighScores(const HighScores *table);
void Storage_InsertScore(HighScores *table, uint32_t value);

#endif
