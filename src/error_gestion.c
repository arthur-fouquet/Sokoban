/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** error_gestion.c
*/

#include "my.h"

int nbr_of_carac(char c, error_t *nb_carac)
{
    if (c != '#' && c != 'O' && c != 'P' && c != 'X' && c != ' ')
        return (84);
    if (c == 'P')
        nb_carac->p += 1;
    if (nb_carac->p > 1)
        return (84);
    if (c == 'O')
        nb_carac->o += 1;
    if (c == 'X')
        nb_carac->x += 1;
    return (0);
}

int check_carac(char **map, int a, error_t *nb_carac)
{
    for (int b = 0; map[a][b] != '\n'; b++) {
        if (nbr_of_carac(map[a][b], nb_carac) == 84)
            return (84);
    }
    return (0);
}

int error_gestion(int ac, char **av)
{
    error_t nb_carac = {0, 0, 0};
    char **map;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (0);
    if (map_char(av[1]) == NULL)
        return (84);
    map = map_2d(map_char(av[1]));
    if (map == NULL)
        return (84);
    for (int a = 0; map[a] != NULL; a++) {
        if (check_carac(map, a, &nb_carac) == 84)
            return (84);
    }
    if (nb_carac.o != nb_carac.x)
        return (84);
    return (0);
}
