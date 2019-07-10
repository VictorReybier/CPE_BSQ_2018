/*
** EPITECH PROJECT, 2018
** convert_file.c
** File description:
** convert char into **char
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **convert(char *filepath, int nb_rows, int nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(size_total(filepath) * sizeof(char));
    int count = read(fd, buffer, (size_total(filepath) + 1));
    char **map = malloc(sizeof(char *) * (nb_rows));
    char **ss = malloc(size_total(filepath) * 100);
    int size_x = 0;
    int size_y = 0;
    int t = 0;

    for (int y = 0; buffer[y] != '\0'; y++)
        size_y += buffer[y] == '\n' ? 1 : 0;
    for (int y = 0; y < size_y; y++) {
        for (size_x = 1; buffer[t + size_x - 1] != '\n'; size_x++)
        ss[y] = malloc(sizeof(char) * (size_x + 1));
        for (int x = 0; x < size_x; x++)
            ss[y][x] = buffer[t + x];
        t += size_x;
    }
    free(buffer);
    return (ss);
}

int is_square_of_size(char **map, int nb_rows, int nb_cols, int square_size)
{
    for (int i = 0; i <= square_size; i++)
        for (int j = 0; j <= square_size; j++)
            if (map[i + nb_rows][j + nb_cols] != '.') {
                return (0);
            }
    return (1);
}