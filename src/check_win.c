/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_win.c
*/

#include "my.h"

int check_win(char **map, int **pos_o)
{
    int count = 0;
    int nb_o = 0;

    for (int a = 0; pos_o[a] != NULL; a++)
        count += 1;
    for (int a = 0; pos_o[a] != NULL; a++) {
        if (map[pos_o[a][0]][pos_o[a][1]] == 'X')
            nb_o += 1;
    }
    if (nb_o == count)
        return (1);
    return (0);
}
