/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** find and display the biggest square of a map
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../my.h"

int size_total(char *filepath)
{
    struct stat sb;
    
    if (stat(filepath, &sb) != 0)
        return (0);
    return (sb.st_size);
}

int size_nb_rows(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer2 = malloc(sizeof(char) * size_total(filepath));
    int count = read(fd, buffer2, (size_total(filepath) - 1));
    int nb_rows = 0;

    for (int i = 0; buffer2[i] != '\n'; i++)
        nb_rows = nb_rows * 10 + (buffer2[i] - 48);
    free(buffer2);
    return (nb_rows);
}

int size_nb_cols(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * size_total(filepath));
    int j = 0;
    int nb_cols = 0;
    read(fd, buffer, (size_total(filepath)));
    for (int i = 0; j < 2; i++) {
        if (buffer[i] == '\n')
            j++;
        if (j == 1)
            nb_cols++;
    }
    free(buffer);
    return (nb_cols);
}

int biggest_square(char **map, int nb_rows, int nb_cols, int i, int j)
{
    int size;
    for (size = 0; i + size <= nb_rows && j + size <= nb_cols; size++)
        if (is_square_of_size(map, i, j, size) == 0)
            break;
    if (nb_rows == 1) {
        for (int n = 0; map[1][n + 1] != '.'; n++) {
            if (map[1][n] == '.') {
                map[1][n] = 'x';
                return (0);
            }
        }
    }
    return (size - 1);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (0);
    int fd = open(av[1], O_RDONLY);
    char *buffer = malloc(sizeof(char) * size_total(av[1]));
    int count = read(fd, buffer, size_total(av[1]));
    int nb_cols = size_nb_cols(av[1]);
    int nb_rows = size_nb_rows(av[1]);
    if (nb_cols == 0 || nb_rows == 0)
        return (0);
    char **map = convert(av[1], 0, 0);
    int x, y;
    int size = -1;
    for (int i = 0; i < nb_rows; i++)
        for (int j = 0; j < nb_cols; j++)
            if (biggest_square(map, nb_rows, nb_cols, i, j) > size) {
                size = biggest_square(map, nb_rows, nb_cols, i, j);
                y = i;
                x = j;
            }
    print_x(size, map, x, y);
    print_map(map, nb_rows);
}