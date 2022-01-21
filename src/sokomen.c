/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokomen.c
*/

#include "my.h"

int get_size(char **map)
{
    int size = my_strlen(map[1]);
    int x = 0;

    for (; map[x] != NULL; x++) {
        if (my_strlen(map[x]) > size)
            size = my_strlen(map[x]);
    }
    return (size);
}

int get_x(char **map)
{
    int size = my_strlen(map[1]);
    int x = 0;

    for (; map[x] != NULL; x++) {
        if (my_strlen(map[x]) > size)
            size = my_strlen(map[x]);
    }
    return (x);
}

void clear_refresh_display(char **map, int x, int size)
{
    clear();
    if (LINES < nb_lines_glob || COLS < nb_columns)
        printw("too small window !");
    else {
        for (int a = 0; map[a] != NULL; a++)
            mvprintw((LINES) / 2 + a - x / 2, (COLS / 2) - (size / 2), map[a]);
    }
    refresh();
}

void end_loop(char **map, yes_t *pos, int **pos_o)
{
    if (check_lose(map) == 1)
        pos->v = 1;
    if (check_win(map, pos_o) == 1)
        pos->v = 0;
}

void sokomen(char **map, yes_t *pos, char *av)
{
    int size = get_size(map);
    int **pos_o = getposo(map);
    int x = get_x(map);

    start();
    while (pos->v == 42) {
        clear_refresh_display(map, x, size);
        if (move_p(map, pos) == 32) {
            map = map_2d(map_char(av));
            *pos = getposp(map);
        }
        end_loop(map, pos, pos_o);
        put_o(map, pos_o);
    }
    endwin();
}
