NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_free_split.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strlcpy.c
SRC = main.c \
	algorithms/adaptive.c \
	algorithms/disorder.c \
	algorithms/medium.c \
	algorithms/simple.c \
	algorithms/complex.c \
	benchmark/benchmark.c \
	benchmark/benchmark_print.c \
	benchmark/benchmark_utils.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	parsing/check_args.c \
	parsing/init_stack.c \
	parsing/parse_args.c \
	utils/error.c \
	utils/sort_utils.c \
	utils/stack_utils.c \
	utils/stack_utils2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_SRC)
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
