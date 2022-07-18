# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:58:26 by fhenrich          #+#    #+#              #
#    Updated: 2022/07/13 15:23:37 by fhenrich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc

RM		= rm -fr

CFLAGS	= -Wall -Werror -Wextra -O

LIBFT	= ./libft

SRCF	= init.c main.c push.c reverse_rotate.c rotate.c sort.c swap.c \
		  utils.c lis.c lis_utils.c sort_utils.c ps_atoi.c sort_short.c

SRCP	= src/

SRC		= $(addprefix $(SRCP), $(SRCF))

OBJ		= $(SRC:.c=.o)


all: libft $(NAME)
	
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT) -lft -o $(NAME)

libft:
	make -C $(LIBFT)

clean:
	make -C $(LIBFT) fclean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft