/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** getposo.c
*/

#include "my.h"

int cond_o(char c, int count)
{
    if (c == 'O')
        count += 1;
    return (count);
}

int set_pos_o(char **map, int y, int **pos_o, int nbr_of_o)
{
    for (int x = 0; map[y][x] != '\n'; x++) {
        if (map[y][x] == 'O') {
            pos_o[nbr_of_o][0] = y;
            pos_o[nbr_of_o][1] = x;
            pos_o[nbr_of_o][2] = -1;
            nbr_of_o += 1;
        }
    }
    return (nbr_of_o);
}

int **mallo_int(char **map)
{
    int **pos_o;
    int count = 0;

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\n'; x++)
            count = cond_o(map[y][x], count);
    }
    pos_o = malloc(sizeof(int *) * (count + 1));
    if (pos_o == NULL)
        return (NULL);
    for (int a = 0; a != count; a++) {
        pos_o[a] = malloc(sizeof(int) * 3);
        if (pos_o[a] == NULL)
            return (NULL);
        pos_o[a][2] = -1;
    }
    pos_o[count] = NULL;
    return (pos_o);
}

int **getposo(char **map)
{
    int **pos_o = mallo_int(map);
    int nbr_of_o = 0;

    for (int y = 0; map[y] != NULL; y++)
        nbr_of_o = set_pos_o(map, y, pos_o, nbr_of_o);
    return (pos_o);
}
