CC	=	gcc -W -Wall -Wextra

GDBCC	=	gcc -g

CFLAGS	+=	-I./include

LDLIBS	=	-lc_graph_prog

TFLAGS	=	--coverage -lcriterion

NAME	=	hunter

GDBNAME	=	gdb

LIB	=	src/lib/my_compute_power_rec.c	\
		src/lib/my_getbase_nbr.c	\
		src/lib/my_putchar.c		\
		src/lib/my_puterror.c		\
		src/lib/my_put_nbr.c		\
		src/lib/my_putstr.c		\
		src/lib/my_strdup.c		\
		src/lib/my_strlen.c

SRC	=	src/window.c		\
		src/timer.c		\
		src/event_dispatcher.c	\
		src/event_poll.c	\
		src/term.c		\
		src/duck/random.c	\
		src/duck/duck.c		\
		src/duck/moves.c	\
		src/duck/anim.c		\
		src/duck/spot.c		\
		src/player.c

MAIN	=	src/main.c

OBJ	=	$(LIB:.c=.o)
OBJ	+=	$(SRC:.c=.o)
OBJ	+=	$(MAIN:.c=.o)

T_NAME	=	unit_tests

T_SRC	=	tests/$(T_NAME).c



.PHONY: clean fclean tclean gclean lib libclean re

all:	lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LDLIBS)

gdb:
	$(GDBCC) $(CFLAGS) $(LDFLAGS) -o $(GDBNAME) $(LIB) $(MAIN) $(SRC) \
		$(LDLIBS)

re: fclean all

regdb: gclean gdb

clean: tclean gclean
	rm -f $(NAME)

fclean:	clean libclean
	rm -f $(OBJ)

gclean:
	rm -f $(GDBNAME)

cclean: gclean fclean libclean
