/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** start.c
*/

#include "my.h"

void start(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}
