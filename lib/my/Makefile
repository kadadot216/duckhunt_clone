SRC	=	str/my_strdup.c		\
		put/my_putchar.c	\
		put/my_putstr.c		\
		put/my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

HDNAME	=	my.h

LIBNAME	=	libmy.a

HDDIR	=	../../include

LIBDIR	=	..

CFLAGS	+=	-I.


all:	.a .h


.a:	$(OBJ)
	ar rc $(LIBNAME) $^
	cp $(LIBNAME) $(LIBDIR)

.h:
	cp $(HDNAME) $(HDDIR)

clean:
	rm -f $(OBJ)
	rm -f $(LIBNAME)

fclean:	clean
	rm -f $(HDDIR)/$(HDNAME)
	rm -f $(LIBDIR)/$(LIBNAME)

