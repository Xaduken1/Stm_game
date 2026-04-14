#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include "joystick.h"
#include "storage.h"

#define LCD_WIDTH           128
#define LCD_HEIGHT          64

#define CELL_SIZE           8
#define GRID_WIDTH          (LCD_WIDTH / CELL_SIZE)
#define GRID_HEIGHT         (LCD_HEIGHT / CELL_SIZE)

#define SNAKE_MAX_LENGTH    128

typedef enum
{
    GAME_BOOT = 0,
    GAME_MENU,
    GAME_PLAY,
	GAME_GAMEOVER,
	GAME_HIGHSCORES
} GameState;

typedef struct
{
    uint8_t x;
    uint8_t y;
} Point;

typedef struct
{
    Point body[SNAKE_MAX_LENGTH];
    uint16_t length;
    JoyDirection dir;
    JoyDirection next_dir;
} Snake;

typedef struct
{
    GameState state;
    Snake snake;
    Point food;
    uint32_t score;
    uint32_t highscore;
    uint8_t need_redraw;
    HighScores table;
    uint8_t menu_index;
} GameContext;

extern GameContext g_game;

void Game_Init(void);
void Game_New(void);
void Game_Process(void);
void Game_OnMoveTick(void);

#endif
