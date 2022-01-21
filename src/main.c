/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main.c
*/

#include "my.h"

void my_h(void)
{
    write(1, "USAGE\n", 6);
    write(1, "      ./my_sokoban map\n", 23);
    write(1, "DESCRIPTION\n", 12);
    write(1, "     map  file representing the warehouse map, containing", 57);
    write(1, " '#' for walls,\n", 16);
    write(1, "          'P' for the player, 'X' for boxes and 'O' for", 55);
    write(1, " storage locations.\n", 19);
}

int main(int ac, char **av)
{
    char **map;
    yes_t pos;

    if (error_gestion(ac, av) == 84)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_h();
        return (0);
    }
    map = map_2d(map_char(av[1]));
    pos = getposp(map);
    sokomen(map, &pos, av[1]);
    for (int a = 0; map[a] != NULL; a++)
        printf("%s", map[a]);
    if (pos.v == 0) {
        write(1, "You won !\n", 10);
        return (0);
    }
    write(1, "You lost !\n", 11);
    return (1);
}
