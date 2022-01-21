/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** put_o.c
*/

#include "my.h"

void put_o(char **map, int **pos_o)
{
    for (int a = 0; pos_o[a] != NULL; a++) {
        if (map[pos_o[a][0]][pos_o[a][1]] == ' ')
            map[pos_o[a][0]][pos_o[a][1]] = 'O';
    }
}
