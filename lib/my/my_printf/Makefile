##
## EPITECH PROJECT, 2022
## library Makefile
## File description:
## library Makefile
##

SRC	=	my_printf_char.c \
		my_printf_dbl_sequel.c \
		my_printf_dbl.c \
		my_printf_dbl_suite.c \
		my_printf_int.c \
		my_printf_parse.c \
		my_printf_str.c \
		my_printf_uint_sequel.c \
		my_printf_uint.c \
		my_printf_utils.c \
		my_printf.c \
		my_putstr.c \
		my_strlen.c \
		my_compute_power_rec.c \
		my_printf_per.c \
		my_strncmp.c \
		my_printf_getpad.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS = --coverage -ggdb3

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f ../include/my_printf.h
	rm -f ../include/my.h

re: fclean all

.PHONY:	all clean fclean re
