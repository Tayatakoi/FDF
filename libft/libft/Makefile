# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 22:22:02 by samamaev          #+#    #+#              #
#    Updated: 2026/01/03 21:11:07 by samamaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORY = ft_atoi.c ft_isalpha.c ft_isprint.c\
ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c\
ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c\
ft_strlcat.c ft_strncmp.c ft_tolower.c\
ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c\
ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_strjoin.c\
ft_substr.c ft_strdup.c ft_strtrim.c ft_split.c\
ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c\
ft_calloc.c ft_strmapi.c ft_wdcounter.c get_next_line.c get_next_line_utils.c\

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
ft_lstlast.c ft_lstadd_back.c ft_lstclear.c\
ft_lstiter.c ft_lstmap.c ft_lstdelone.c\

OBJ_PATH = ${MANDATORY:.c=.o}
BONUS_PATH = ${BONUS:.c=.o}

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

$(NAME): ${OBJ_PATH}
	ar rcs ${NAME} ${OBJ_PATH}

all: ${NAME}

clean:
	${RM} ${OBJ_PATH} ${BONUS_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: ${OBJ_PATH} ${BONUS_PATH}
	ar rcs ${NAME} ${OBJ_PATH} ${BONUS_PATH}

.PHONY: all clean fclean re bonus