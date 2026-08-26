NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I..
AR = ar rcs
RM = rm -f
SRC = ft_bzero.c \
	ft_calloc.c \
	ft_free_split.c \
	ft_split.c \
	ft_strlcpy.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
