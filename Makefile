NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/*.c \
      get-next-line/*.c

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
MLX = minilibx-linux/libmlx.a

MLX_FLAGS = -lXext -lX11
MATH = -lm

all: $(NAME)

$(NAME):
	make -C libft
	make -C printf
	make -C minilibx-linux
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) \
	$(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) $(MATH)

clean:
	make -C libft clean
	make -C printf clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re

