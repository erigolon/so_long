# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 18:35:59 by erigolon          #+#    #+#              #
#    Updated: 2023/05/12 12:44:51 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS: find ./srcs -iname "*.c"

# //= Variables =//

# /Users/erigolon/.brew/opt/glfw/lib 
# /opt/homebrew/Cellar/glfw/3.3.8/lib/

NAME	= so_long
LIBMLX	= ./MLX42
LIBFT	= ./libft
LIBPF	= ./printf
LIBGN	= ./get_next_line

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGN} -I ${LIBPF}
LIBGL	= -lglfw -L"/Users/erigolon/.brew/opt/glfw/lib"
LIBS	= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBPF}/libftprintf.a ${LIBGN}/get_next_line.a
SRCS	= main.c \
			check_map.c \
			check_map_2.c \
			collectibles.c \
			images.c \
			map.c \
			move.c

OBJS	= ${SRCS:.c=.o}

# //= Recipes =//

all: libft libmlx libpf libgn ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libpf:
	@${MAKE} -C ${LIBPF}

libgn:
	@${MAKE} -C ${LIBGN}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPF} clean
	@${MAKE} -C ${LIBGN} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPF} fclean
	@${MAKE} -C ${LIBGN} fclean
	
re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft