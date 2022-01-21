/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** getmap.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int file_size(char const *filepath)
{
    struct stat nb_lines;
    int size;

    if (stat(filepath, &nb_lines) == -1)
        return (84);
    size = nb_lines.st_size;
    return (size);
}

char *map_char(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size;
    char *map;

    if (fd == -1)
        return NULL;
    size = file_size(filepath);
    if (size == 84)
        return NULL;
    map = malloc(size + 1);
    if (map == NULL)
        return NULL;
    if (read(fd, map, size) == -1)
        return NULL;
    if (map[size - 1] != '\n')
        return NULL;
    close(fd);
    map[size] = '\0';
    return (map);
}
