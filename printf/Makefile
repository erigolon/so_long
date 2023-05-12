# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 10:19:03 by erigolon          #+#    #+#              #
#    Updated: 2023/01/19 09:38:11 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ar rcs

SRC = ft_printf.c \
	ft_putcharf.c \
	ft_putstrf.c \
	ft_check_percentage.c \
	ft_itoa_u.c \
	ft_hex.c \
	ft_strlen.c \
	ft_itoa.c \

OBJ = ${SRC:.c=.o}

RM = rm -f

CC = GCC

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re