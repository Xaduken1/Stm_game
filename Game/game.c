#include "game.h"
#include "snake.h"
#include "render.h"
#include "display.h"
#include "joystick.h"
#include "storage.h"
#include "random.h"
#include "timer.h"

GameContext g_game;

static void Game_SpawnFood(void)
{
    do
    {
        g_game.food.x = (uint8_t)Random_Range(0, GRID_WIDTH - 1);
        g_game.food.y = (uint8_t)Random_Range(0, GRID_HEIGHT - 1);
    }
    while (Snake_Contains(&g_game.snake, g_game.food.x, g_game.food.y));
}

void Game_New(void)
{
    Snake_Init(&g_game.snake);
    g_game.score = 0;
    Game_SpawnFood();
    g_game.state = GAME_PLAY;
    g_game.need_redraw = 1;
}

void Game_Init(void)
{
    Random_Init(HAL_GetTick());

    Storage_LoadHighScores(&g_game.table);
    g_game.highscore = g_game.table.scores[0];

    g_game.menu_index = 0;
    g_game.state = GAME_MENU;
    g_game.need_redraw = 1;
}

void Game_OnMoveTick(void)
{
    if (g_game.state != GAME_PLAY)
        return;

    uint8_t ate_food = 0;

    if (!Snake_Step(&g_game.snake, g_game.food, &ate_food))
    {
        Storage_InsertScore(&g_game.table, g_game.score);
        Storage_SaveHighScores(&g_game.table);
        g_game.highscore = g_game.table.scores[0];

        g_game.state = GAME_GAMEOVER;
        g_game.need_redraw = 1;
        return;
    }


    if (ate_food)
    {
        g_game.score++;
        Game_SpawnFood();
    }

    g_game.need_redraw = 1;
}

void Game_Process(void)
{
    static JoyDirection last_menu_dir = JOY_NONE;
    static uint8_t ignore_click = 0;

    JoyDirection dir = Joystick_GetDirection();
    uint8_t click = Joystick_ButtonClicked();

    if (!Joystick_ButtonPressed())
    {
        ignore_click = 0;
    }

    switch (g_game.state)
    {
        case GAME_MENU:
        {
            if (dir == JOY_NONE)
            {
                last_menu_dir = JOY_NONE;
            }
            else if (dir == JOY_UP && last_menu_dir == JOY_NONE)
            {
                if (g_game.menu_index > 0)
                    g_game.menu_index--;

                last_menu_dir = dir;
                g_game.need_redraw = 1;
            }
            else if (dir == JOY_DOWN && last_menu_dir == JOY_NONE)
            {
                if (g_game.menu_index < 1)
                    g_game.menu_index++;

                last_menu_dir = dir;
                g_game.need_redraw = 1;
            }

            if (click && !ignore_click)
            {
                ignore_click = 1;

                if (g_game.menu_index == 0)
                {
                    Game_New();
                    return;   // ВАЖНО
                }
                else
                {
                    Storage_LoadHighScores(&g_game.table);
                    g_game.state = GAME_HIGHSCORES;
                    g_game.need_redraw = 1;
                    return;   // ВАЖНО
                }
            }

            if (g_game.need_redraw)
            {
                Render_Menu();
                Display_Update();
                g_game.need_redraw = 0;
            }
            break;
        }

        case GAME_PLAY:
        {
            if (dir != JOY_NONE &&
                !Snake_IsOppositeDirection(g_game.snake.dir, dir))
            {
                g_game.snake.next_dir = dir;
            }

            if (g_move_tick_flag)
            {
                g_move_tick_flag = 0;
                GameState prev_state = g_game.state;
                Game_OnMoveTick();

                if (g_game.state != prev_state)
                    return;   // ВАЖНО
            }

            if (g_game.need_redraw)
            {
                Render_Game();
                Display_Update();
                g_game.need_redraw = 0;
            }
            break;
        }

        case GAME_GAMEOVER:
        {
            if (g_game.need_redraw)
            {
                Render_GameOver();
                Display_Update();
                g_game.need_redraw = 0;
            }

            if (click && !ignore_click)
            {
                ignore_click = 1;
                g_game.menu_index = 0;
                g_game.state = GAME_MENU;
                g_game.need_redraw = 1;
                return;   // ВАЖНО
            }
            break;
        }

        case GAME_HIGHSCORES:
        {
            if (g_game.need_redraw)
            {
                Render_HighScores();
                Display_Update();
                g_game.need_redraw = 0;
            }

            if (click && !ignore_click)
            {
                ignore_click = 1;
                g_game.state = GAME_MENU;
                g_game.need_redraw = 1;
                return;   // ВАЖНО
            }
            break;
        }

        default:
            break;
    }
}
