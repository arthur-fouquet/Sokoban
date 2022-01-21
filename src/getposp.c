/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** getposp.c
*/

#include "my.h"

void condition(char c, yes_t *pos, int x, int y)
{
    if (c == 'P') {
        pos->x = x;
        pos->y = y;
    }
}

yes_t getposp(char **map)
{
    yes_t pos;

    pos.x = 0;
    pos.y = 0;
    pos.v = 42;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\n'; x++)
            condition(map[y][x], &pos, x, y);
    }
    return (pos);
}
