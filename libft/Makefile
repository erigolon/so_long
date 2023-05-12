# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:33:44 by erigolon          #+#    #+#              #
#    Updated: 2023/03/10 13:49:51 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = ar rcs

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRCBON = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \

OBJ = ${SRC:.c=.o}

OBJBON = ${SRCBON:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	
bonus:
	$(CC) $(CFLAGS) -c $(SRCBON)
	$(LIB) $(NAME) $(OBJBON)

clean:
	$(RM) $(OBJ) $(OBJBON)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus