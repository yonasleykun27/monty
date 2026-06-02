CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c90
SRC = main.c execute.c opcodes_1.c opcodes_2.c opcodes_3.c stack_utils.c
OBJ = $(SRC:.c=.o)
NAME = monty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
