# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 17:18:12 by tgerdes           #+#    #+#              #
#    Updated: 2022/03/10 11:58:35 by fhenrich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/*.c

OBJS = ${SRCS:.c=.o}

LIBFT = ./libft

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

EXT_LIB = libmlx.a

UNAME := $(shell uname)

all: ${EXT_LIB} libft.a ${NAME}

ifeq ($(UNAME), Linux)
MINILIBX = ./mlx

%.o: %.c
		${CC} ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o ${<:.c=.o}

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(EXT_LIB) -g $(CFLAGS) -L/usr/include/X11/extensions -lX11 -lXext -L $(LIBFT) -lft -o $(NAME)

endif

ifeq ($(UNAME), Darwin)
MINILIBX = ./mlxmac

%.o: %.c
		${CC} ${CFLAGS} -Imlxmac -c $< -o ${<:.c=.o}

$(NAME): $(SRCS)
	$(CC) -g -Lmlx -L $(MINILIBX) -lmlx -framework OpenGL -framework AppKit -L $(LIBFT) -lft $(SRCS) -o $(NAME)

endif

${EXT_LIB}:
	make -C ${MINILIBX}
	cp ${MINILIBX}/${EXT_LIB} .
	cp ${MINILIBX}/mlx.h src

libft.a:
	make -C ${LIBFT}
	cp ${LIBFT}/libft.h src

archive:
	ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} a.out src/mlx.h src/libft.h

fclean: clean
		${RM} ${NAME} ${EXT_LIB}
		make -C ${LIBFT} fclean
		make -C ${MINILIBX} clean

re:		fclean all
