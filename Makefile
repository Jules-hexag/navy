##
## EPITECH PROJECT, 2022
## makefile
## File description:
## il fait le projet
##

SRC 	=	src/main.c \
			src/my_navy.c \
			src/user_input/help.c \
			src/user_input/user_input.c \
			src/user_input/verify_file_validity/file_validity.c \
			src/create_map/ships/vertical_evolution_ships.c \
			src/create_map/ships/horizontal_evolution_ships.c \
			src/create_map/create_map.c \
			src/create_map/create_enemy_map.c \
			src/print_shoot_result.c \
			src/receive_shoot.c \
			src/is_there_a_winner.c \
			src/sigcom/colgate.c \
			src/sigcom/handshake.c \
			src/print_map/print_map.c

TESTS_SRC	=	bonus/tests.c \

OBJ		= 	$(SRC:.c=.o)

T_OBJ	=	$(TESTS_SRC:.c=.o)

NAME 	=	navy

TESTS	=	unit_tests

LIB 	=	lib/libmy.a

LDFLAGS = 	-L./lib

LDLIBS	=	-lmy

CFLAGS	=	-I./include -O2 -Wall -Wextra

CFLAGS_DEBUG	=	-I./include -ggdb3 -fsanitize=address

CFLAGS_TESTS	=	-I./include -ggdb3 -O0 --coverage

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(TESTS): CFLAGS=$(CFLAGS_TESTS)
$(TESTS): re $(T_OBJ)
	gcc -o $@ $(T_OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -lcriterion

$(LIB):
	make -C lib/my/

debug: CFLAGS=$(CFLAGS_DEBUG)
debug: re

clean:
	@$(RM) -vf $(OBJ)
	@$(RM) -vf $(T_OBJ)
	@$(RM) -vf $(TESTS)

tests_run: $(TESTS)
	./$(TESTS) --always-succeed
	gcovr --exclude bonus/tests.c
	gcovr --branches --exclude bonus/tests.c

fclean: clean
	@$(RM) -vf $(NAME)
	make fclean -C lib/my/

re: fclean all

.PHONY: all clean fclean re tests_run unit_tests
