/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my_struct.h"

char *map_char(char const *filepath);
int my_strlen(char const *str);
char **map_2d(char *map_char);
void sokomen(char **map, yes_t *pos, char *av);
yes_t getposp(char **map);
int move_p(char **map, yes_t *pos);
void start(void);
int **getposo(char **map);
void put_o(char **map, int **pos_o);
int check_win(char **map, int **pos_o);
int check_lose(char **map);
int error_gestion(int ac, char **av);
void my_putstr(char const *str);

#endif
