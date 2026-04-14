#include "render.h"
#include "game.h"
#include "framebuffer.h"
#include <stdio.h>
#include "storage.h"

extern GameContext g_game;

static void Render_SnakeCell(uint8_t gx, uint8_t gy)
{
    FB_FillRect(gx * CELL_SIZE, gy * CELL_SIZE, CELL_SIZE, CELL_SIZE, 1);
}

static void Render_FoodCell(uint8_t gx, uint8_t gy)
{
    FB_DrawRect(gx * CELL_SIZE + 1, gy * CELL_SIZE + 1, CELL_SIZE - 2, CELL_SIZE - 2, 1);
}

void Render_Menu(void)
{
    FB_Clear(0);

    FB_DrawString6x8(34, 4, "SNAKE", 1);

    if (g_game.menu_index == 0)
        FB_DrawString6x8(10, 24, "> START", 1);
    else
        FB_DrawString6x8(16, 24, "START", 1);

    if (g_game.menu_index == 1)
        FB_DrawString6x8(10, 38, "> SCORES", 1);
    else
        FB_DrawString6x8(16, 38, "SCORES", 1);
}

void Render_Game(void)
{
    char buf[20];

    FB_Clear(0);

    for (uint16_t i = 0; i < g_game.snake.length; i++)
        Render_SnakeCell(g_game.snake.body[i].x, g_game.snake.body[i].y);

    Render_FoodCell(g_game.food.x, g_game.food.y);

    snprintf(buf, sizeof(buf), "%lu", (unsigned long)g_game.score);
    FB_DrawString6x8(0, 0, buf, 0);
}

void Render_GameOver(void)
{
    char buf[24];

    FB_Clear(0);

    FB_DrawString6x8(22, 8, "GAME OVER", 1);

    snprintf(buf, sizeof(buf), "SCORE %lu", (unsigned long)g_game.score);
    FB_DrawString6x8(18, 24, buf, 1);

    snprintf(buf, sizeof(buf), "BEST %lu", (unsigned long)g_game.highscore);
    FB_DrawString6x8(22, 36, buf, 1);

    FB_DrawString6x8(8, 52, "PRESS BTN", 1);
}

void Render_HighScores(void)
{
    char buf[24];

    FB_Clear(0);
    FB_DrawString6x8(22, 0, "HIGHSCORES", 1);

    for (int i = 0; i < HIGHSCORES_COUNT; i++)
    {
        snprintf(buf, sizeof(buf), "%d. %lu", i + 1, (unsigned long)g_game.table.scores[i]);
        FB_DrawString6x8(8, 12 + i * 10, buf, 1);
    }

    FB_DrawString6x8(10, 56, "BTN BACK", 1);
}
