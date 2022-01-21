/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_lose.c
*/

#include "my.h"

int around_x_bis(char **map, int y, int x)
{
    if (map[y][x] == 'X') {
        if ((map[y + 1][x] == '#' || map[y + 1][x] == 'X') && \
            (map[y][x - 1] == '#' || map[y][x - 1] == 'X'))
            return (1);
        if ((map[y - 1][x] == '#' || map[y - 1][x] == 'X') && \
            (map[y][x + 1] == '#' || map[y][x + 1] == 'X'))
            return (1);
        if ((map[y - 1][x] == '#' || map[y - 1][x] == 'X') && \
            (map[y][x - 1] == '#' || map[y][x - 1] == 'X'))
            return (1);
    }
    return (0);
}

int around_x(char **map, int y, int x)
{
    if (map[y][x] == 'X') {
        if ((map[y][x + 1] == '#' || map[y][x + 1] == 'X') && \
            (map[y + 1][x] == '#' || map[y + 1][x] == 'X'))
            return (1);
        if ((map[y][x + 1] == '#' || map[y][x + 1] == 'X') && \
            (map[y - 1][x] == '#' || map[y - 1][x] == 'X'))
            return (1);
        if ((map[y][x - 1] == '#' || map[y][x - 1] == 'X') && \
            (map[y + 1][x] == '#' || map[y + 1][x] == 'X'))
            return (1);
        if ((map[y][x - 1] == '#' || map[y][x - 1] == 'X') && \
            (map[y - 1][x] == '#' || map[y - 1][x] == 'X'))
            return (1);
        if ((map[y + 1][x] == '#' || map[y + 1][x] == 'X') && \
            (map[y][x + 1] == '#' || map[y][x + 1] == 'X'))
            return (1);
    }
    return (0);
}

int check_lose_bis(char **map, int y, int count_x_lock)
{
    for (int x = 0; map[y][x] != '\n'; x++) {
        if (around_x(map, y, x) == 1 || around_x_bis(map, y, x))
            count_x_lock += 1;
    }
    return (count_x_lock);
}

int check_lose(char **map)
{
    int a = 0;
    int b = 0;
    int count = 0;
    int count_x_lock = 0;

    while (map[a] != NULL) {
        if (map[a][b] == '\n') {
            a++;
            b = 0;
        }
        else if (map[a][b] == 'X')
            count++;
        b++;
    }
    for (int y = 0; map[y] != NULL; y++)
        count_x_lock = check_lose_bis(map, y, count_x_lock);
    if (count == count_x_lock)
        return (1);
    return (0);
}
