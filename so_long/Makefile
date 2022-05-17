# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 10:09:51 by fhenrich          #+#    #+#              #
#    Updated: 2022/05/17 12:59:53 by fhenrich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/*.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

EXT_LIB = libmlx.a

UNAME := $(shell uname)

all: $(EXT_LIB) libft.a $(NAME)

ifeq ($(UNAME), Linux)
MINILIBX = ./mlx

%.o: %.c
		$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $(<:.c=.o)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(EXT_LIB) -g $(CFLAGS) -L/usr/include/X11/extensions -lX11 -lXext -L $(LIBFT) -lft -o $(NAME)

endif

ifeq ($(UNAME), Darwin)
MINILIBX = ./mlxmac

%.o: %.c
		$(CC) $(CFLAGS) -Imlxmac -c $< -o $(<:.c=.o)

$(NAME): $(SRCS)
	$(CC) -Lmlx -L $(MINILIBX) -lmlx -framework OpenGL -framework AppKit -L $(LIBFT) -lft $(SRCS) -o $(NAME)

endif

$(EXT_LIB):
	make -C $(MINILIBX)
	cp $(MINILIBX)/$(EXT_LIB) .

libft.a:
	make -C $(LIBFT)

archive:
	ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) a.out src/mlx.h src/libft.h
		make -C $(LIBFT) fclean
		make -C $(MINILIBX) clean

fclean: clean
		$(RM) $(NAME) $(EXT_LIB)

re:		fclean all
