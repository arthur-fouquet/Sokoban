##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/getmap.c		\
		src/my_strlen.c		\
		src/map_2d.c		\
		src/sokomen.c		\
		src/getposp.c		\
		src/move_p.c		\
		src/start.c		\
		src/getposo.c		\
		src/put_o.c		\
		src/check_win.c		\
		src/check_lose.c	\
		src/error_gestion.c	\

NAME	=	my_sokoban

CC	=	gcc

CPPFLAGS=       $(INCLUDE)

CFLAGS	=	-Wall -Wextra -g3 -lncurses

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./include

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re test_run
