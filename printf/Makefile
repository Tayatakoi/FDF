# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 21:29:42 by samamaev          #+#    #+#              #
#    Updated: 2025/08/25 16:45:22 by samamaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MANDATORY = ft_printf.c ft_for_conversion.c\
ft_putstr_fd.c ft_putchar_fd.c ft_print_int.c\
ft_putnbr_fd.c ft_handling.c ft_print_pointer.c\
ft_puthex_fd.c ft_print_unsigned.c ft_print_hex.c\

OBJ_PATH = ${MANDATORY:.c=.o}

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJ_PATH}
	ar rcs ${NAME} ${OBJ_PATH}

all: ${NAME}

clean:
	${RM} ${OBJ_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re