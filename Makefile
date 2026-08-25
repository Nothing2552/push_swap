NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
SRC = main.c \
	algorithms/simple.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	parsing/check_args.c \
	parsing/init_stack.c \
	parsing/parse_args.c \
	utils/error.c \
	utils/stack_utils.c \
	utils/stack_utils2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
