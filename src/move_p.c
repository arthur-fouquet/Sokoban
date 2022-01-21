/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move.c
*/

#include "my.h"

void down(char **map, yes_t *pos)
{
    if (map[pos->y + 1][pos->x] == '#')
        return;
    if (map[pos->y + 1][pos->x] == 'X') {
        if (map[pos->y + 2][pos->x] == '#')
            return;
        if (map[pos->y + 2][pos->x] == 'X')
            return;
        map[pos->y + 2][pos->x] = 'X';
    }
    map[pos->y][pos->x] = ' ';
    pos->y += 1;
    map[pos->y][pos->x] = 'P';
}

void up(char **map, yes_t *pos)
{
    if (map[pos->y - 1][pos->x] == '#')
        return;
    if (map[pos->y - 1][pos->x] == 'X') {
        if (map[pos->y - 2][pos->x] == '#')
            return;
        if (map[pos->y - 2][pos->x] == 'X')
            return;
        map[pos->y - 2][pos->x] = 'X';
    }
    map[pos->y][pos->x] = ' ';
    pos->y -= 1;
    map[pos->y][pos->x] = 'P';
}

void left(char **map, yes_t *pos)
{
    if (map[pos->y][pos->x - 1] == '#')
        return;
    if (map[pos->y][pos->x - 1] == 'X') {
        if (map[pos->y][pos->x - 2] == '#')
            return;
        if (map[pos->y][pos->x - 2] == 'X')
            return;
        map[pos->y][pos->x - 2] = 'X';
    }
    map[pos->y][pos->x] = ' ';
    pos->x -= 1;
    map[pos->y][pos->x] = 'P';
}

void right(char **map, yes_t *pos)
{
    if (map[pos->y][pos->x + 1] == '#')
        return;
    if (map[pos->y][pos->x + 1] == 'X') {
        if (map[pos->y][pos->x + 2] == '#')
            return;
        if (map[pos->y][pos->x + 2] == 'X')
            return;
        map[pos->y][pos->x + 2] = 'X';
    }
    map[pos->y][pos->x] = ' ';
    pos->x += 1;
    map[pos->y][pos->x] = 'P';
}

int move_p(char **map, yes_t *pos)
{
    int c = getch();

    if (c == KEY_DOWN)
        down(map, pos);
    if (c == KEY_UP)
        up(map, pos);
    if (c == KEY_LEFT)
        left(map, pos);
    if (c == KEY_RIGHT)
        right(map, pos);
    return (c);
}
