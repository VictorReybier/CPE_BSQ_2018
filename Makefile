##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME =	bsq

OBJ	=	$(SRC:.c=.o)

SRC	=	src/convert_file.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c		\
		src/bsq.c			\
		src/print_bsq.c		\

all:
		gcc -o $(NAME) $(SRC) -lm
		ar rc libmy.a $(SRC)

clean:
		rm -f *.o

fclean:	clean
		rm -rf $(NAME)

re:		fclean all