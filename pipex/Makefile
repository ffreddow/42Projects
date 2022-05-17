# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 09:12:00 by fhenrich          #+#    #+#              #
#    Updated: 2022/05/17 12:58:21 by fhenrich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex

LIBFT=./libft

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRCS=src/*.c

OBJS=$(SRCS:.c=.o)

RM=rm -fr

all: libft.a $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -L $(LIBFT) -lft -o $(NAME)

libft.a:
	make -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) fclean

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME) libft.a
