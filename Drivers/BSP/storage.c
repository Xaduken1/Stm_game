#include "storage.h"
#include "fatfs.h"
#include "ff.h"
#include <string.h>

uint32_t g_storage_debug_code = 0;
static uint8_t s_storage_ok = 0;

uint8_t Storage_Init(void)
{
    FRESULT res = f_mount(&SDFatFS, SDPath, 1);
    g_storage_debug_code = 1000 + res;
    s_storage_ok = (res == FR_OK) ? 1 : 0;
    return s_storage_ok;
}

uint8_t Storage_LoadHighScores(HighScores *table)
{
    if (!table)
    {
        g_storage_debug_code = 2001;
        return 0;
    }

    memset(table, 0, sizeof(HighScores));

    if (!s_storage_ok)
    {
        g_storage_debug_code = 2002;
        return 0;
    }

    FIL file;
    UINT br = 0;

    FRESULT res = f_open(&file, "scores.dat", FA_READ);
    g_storage_debug_code = 2100 + res;

    if (res != FR_OK)
        return 0;

    res = f_read(&file, table, sizeof(HighScores), &br);
    g_storage_debug_code = 2200 + res;

    f_close(&file);

    if (res != FR_OK || br != sizeof(HighScores))
    {
        g_storage_debug_code = 2300 + br;
        memset(table, 0, sizeof(HighScores));
        return 0;
    }

    return 1;
}

uint8_t Storage_SaveHighScores(const HighScores *table)
{
    if (!table)
    {
        g_storage_debug_code = 3001;
        return 0;
    }

    if (!s_storage_ok)
    {
        g_storage_debug_code = 3002;
        return 0;
    }

    FIL file;
    UINT bw = 0;

    FRESULT res = f_open(&file, "scores.dat", FA_CREATE_ALWAYS | FA_WRITE);
    g_storage_debug_code = 3100 + res;
    if (res != FR_OK)
        return 0;

    res = f_write(&file, table, sizeof(HighScores), &bw);
    g_storage_debug_code = 3200 + res;
    if (res != FR_OK)
    {
        f_close(&file);
        return 0;
    }

    res = f_sync(&file);
    g_storage_debug_code = 3300 + res;

    f_close(&file);

    if (res != FR_OK || bw != sizeof(HighScores))
    {
        g_storage_debug_code = 3400 + bw;
        return 0;
    }

    return 1;
}

void Storage_InsertScore(HighScores *table, uint32_t value)
{
    if (!table)
        return;

    for (int i = 0; i < HIGHSCORES_COUNT; i++)
    {
        if (value > table->scores[i])
        {
            for (int j = HIGHSCORES_COUNT - 1; j > i; j--)
                table->scores[j] = table->scores[j - 1];

            table->scores[i] = value;
            return;
        }
    }
}

uint32_t Storage_LoadHighScore(void)
{
    HighScores table;
    if (Storage_LoadHighScores(&table))
        return table.scores[0];
    return 0;
}
