#include "snake.h"

void Snake_Init(Snake *snake)
{
    snake->length = 3;
    snake->dir = JOY_RIGHT;
    snake->next_dir = JOY_RIGHT;

    snake->body[0].x = 5; snake->body[0].y = 3;
    snake->body[1].x = 4; snake->body[1].y = 3;
    snake->body[2].x = 3; snake->body[2].y = 3;
}

uint8_t Snake_IsOppositeDirection(JoyDirection a, JoyDirection b)
{
    if ((a == JOY_LEFT  && b == JOY_RIGHT) ||
        (a == JOY_RIGHT && b == JOY_LEFT)  ||
        (a == JOY_UP    && b == JOY_DOWN)  ||
        (a == JOY_DOWN  && b == JOY_UP))
    {
        return 1;
    }

    return 0;
}

uint8_t Snake_Contains(const Snake *snake, uint8_t x, uint8_t y)
{
    for (uint16_t i = 0; i < snake->length; i++)
    {
        if (snake->body[i].x == x && snake->body[i].y == y)
            return 1;
    }
    return 0;
}

uint8_t Snake_Step(Snake *snake, Point food, uint8_t *ate_food)
{
    Point new_head = snake->body[0];
    snake->dir = snake->next_dir;
    *ate_food = 0;

    switch (snake->dir)
    {
        case JOY_UP:
            if (new_head.y == 0) return 0;
            new_head.y--;
            break;

        case JOY_DOWN:
            new_head.y++;
            if (new_head.y >= GRID_HEIGHT) return 0;
            break;

        case JOY_LEFT:
            if (new_head.x == 0) return 0;
            new_head.x--;
            break;

        case JOY_RIGHT:
            new_head.x++;
            if (new_head.x >= GRID_WIDTH) return 0;
            break;

        default:
            break;
    }

    // Проверка столкновения с телом
    for (uint16_t i = 0; i < snake->length; i++)
    {
        if (snake->body[i].x == new_head.x && snake->body[i].y == new_head.y)
            return 0;
    }

    if (new_head.x == food.x && new_head.y == food.y)
    {
        *ate_food = 1;
        if (snake->length < SNAKE_MAX_LENGTH)
            snake->length++;
    }

    for (int i = snake->length - 1; i > 0; i--)
    {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = new_head;
    return 1;
}
