##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc -Wall -Wextra

RM	=	rm -f

NAME	=	sokoban

SRC	=	src/main.c	\
		src/helper.c	\
		src/key_check.c	\
		src/loose_check.c	\
		src/find_player.c	\
		src/map_check.c	\
		src/map_reading.c	\
		src/move_box.c	\
		src/movement.c	\
		src/play.c	\
		src/win_check.c	\
		src/zone_check.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\

CFLAGS	+=	-I./include/

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
