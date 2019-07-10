/*
** EPITECH PROJECT, 2018
** print_bsq.c
** File description:
** print map and 'x'
*/

#include "../my.h"

int print_x(int size, char **map, int x, int y)
{
    for (int i = 0; i <= size; i++)
        for (int j = 0; j <= size; j++)
            map[i + y][j + x] = 'x';
}

int print_map(char **map, int nb_rows)
{
    if (nb_rows == 0)
        my_putstr("Empty file");
    for (int i = 1; i <= nb_rows; i++)
        my_putstr(map[i]);
}