/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototype fonction
*/

char **convert(char *filepath, int nb_rows, int nb_cols);
int is_square_of_size(char **map, int nb_rows, int nb_cols, int square_size);
int size_total(char *filepath);
int size_nb_rows(char *filepath);
int size_nb_cols(char *filepath);
int biggest_square(char **map, int nb_rows, int nb_cols, int i, int j);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
int print_x(int size, char **map, int x, int y);
int print_map(char **map, int nb_rows);
