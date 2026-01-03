# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/02 22:45:33 by samamaev          #+#    #+#              #
#    Updated: 2026/01/03 22:58:43 by samamaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -no-pie
RM = rm -rf

SRCS = src/fdf.c src/parse.c src/utils.c src/render.c src/main.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = src_bonus/fdf_bonus.c src_bonus/parse_bonus.c \
			src_bonus/utils_bonus.c src_bonus/math_bonus.c src_bonus/main_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -Llibft -lft -o $(NAME)

bonus: $(OBJS_BONUS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_FLAGS) -Llibft -lft -o $(NAME)

libft/libft.a:
	$(MAKE) -C libft
	$(MAKE) -C mlx

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
