##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for myhunter
##

CC	=	gcc -W -Wall -Wextra

GDBCC	=	gcc -g

CFLAGS	+=	-I./include

LDFLAGS	=	-L./lib

LDLIBS	=	-lc_graph_prog -lmy

TFLAGS	=	--coverage -lcriterion

NAME	=	my_hunter

GDBNAME	=	gdb

SRC	=	src/window.c		\
		src/timer.c		\
		src/game_events.c	\
		src/term.c		\
		src/duck/duck.c		\
		src/duck/moves.c	\
		src/player.c

OBJ	=	$(SRC:.c=.o)

MAIN	=	src/main.c

T_NAME	=	unit_tests

T_SRC	=	tests/$(T_NAME).c



.PHONY: clean fclean tclean gclean lib libclean re

all:	lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(MAIN) $(SRC) $(LDLIBS)

tests_run:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(T_NAME) $(T_SRC) $(SRC)	\
						$(LDLIBS) $(TFLAGS)
	./$(T_NAME)

gdb:
	$(GDBCC) $(CFLAGS) $(LDFLAGS) -o $(GDBNAME) $(MAIN) $(SRC) $(LDLIBS)

retest: tclean tests_run

re: fclean all

regdb: gclean gdb

lib:
	make -C ./lib/my
	make -C ./lib/my clean

libclean:
	make -C ./lib/my fclean


clean: tclean gclean
	rm -f $(OBJ)

fclean:	clean libclean
	rm -f $(NAME)

tclean:
	rm -f $(T_NAME)
	rm -f *.gc*

gclean:
	rm -f $(GDBNAME)

cclean: tclean gclean fclean libclean
