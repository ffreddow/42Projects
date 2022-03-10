# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 09:56:13 by fhenrich          #+#    #+#              #
#    Updated: 2022/03/10 12:14:05 by fhenrich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SOURCE= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_strlcpy.c ft_bzero.c ft_memcpy.c\
		ft_memmove.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c\
		ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_itoa.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c\
		ft_putstr_new.c ft_putptr.c ft_putchar_new.c ft_printf.c ft_base.c

BONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c

BNS= $(BONUS:.c=.o)

OBJS = $(SOURCE:.c=.o)

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} *.o

fclean:	clean
		${RM} ${NAME}

re:		fclean all

test: fclean
	gcc $(SRCS)

bonus: $(NAME)
	$(CC) $(CFLAGS) -c $(BONUS)
	ar rcs $(NAME) $(BNS)

.PHONY: all, re, clean, fclean, make, bonus