/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** map_2d.c
*/

#include "my.h"

int nb_column(char *map_char, int mallo)
{
    int a = 0;
    int count = 0;

    while (mallo != 0) {
        while (map_char[a] != '\n' && map_char[a] != '\0') {
            a++;
        }
        a += 2;
        mallo--;
    }
    while (map_char[a] != '\n' && map_char[a] != '\0') {
        a++;
        count++;
    }
    nb_columns = count;
    return (count);
}

char **mallo(char *map_char)
{
    char **map_2d;
    int nb_lines = 0;

    for (int a = 0; map_char[a] != '\0'; a++) {
        if (map_char[a] == '\n')
            nb_lines += 1;
    }
    nb_lines_glob = nb_lines;
    map_2d = malloc(sizeof(char *) * (nb_lines + 1));
    if (map_2d == NULL)
        return (NULL);
    for (int mallo = 0; mallo < nb_lines; mallo++) {
        map_2d[mallo] = malloc(sizeof(int) * (nb_column(map_char, mallo) + 1));
        if (map_2d[mallo] == NULL)
            return (NULL);
    }
    map_2d[nb_lines] = NULL;
    return (map_2d);
}
char **map_2d(char *map_char)
{
    char **map_2d;
    int a = 0;
    int b = 0;
    int c = 0;

    if (map_char == NULL)
        return (NULL);
    map_2d = mallo(map_char);
    while (map_char[a] != '\0') {
        for (; map_char[a] != '\n' && map_char[a] != '\0'; c++) {
            map_2d[b][c] = map_char[a];
            a++;
        }
        map_2d[b][c] = '\n';
        a++;
        b++;
        c = 0;
    }
    map_2d[b] = NULL;
    return (map_2d);
}
