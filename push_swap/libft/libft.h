/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:39:49 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 17:10:17 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_print
{
	va_list	args;
	int		total_len;
}	t_print;

int				ft_isalpha(int arg);
int				ft_isdigit(int arg);
int				ft_isalnum(int arg);
int				ft_isascii(int arg);
int				ft_isprint(int arg);
int				ft_toupper(int arg);
int				ft_tolower(int arg);
int				ft_atoi(const char *src);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strlen(const char *str);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
int				ft_lstsize(t_list *lst);
int				find_char(const char *str, unsigned char c);
int				ft_strlen(const char *str);
int				ft_printf(const char *s, ...);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strdup(const char *src);
char			*ft_strnstr(const char *str1, const char *str2, size_t n);
char			*ft_substr(char const *s, size_t start, size_t len);
char			*ft_strjoin(const char *str1, const char *str2);
char			*get_next_line(int fd);
void			ft_putchar(char c, t_print *count);
void			ft_putstr(char *str, t_print *counter);
void			ft_base(long double num, char *content, t_print *counter);
void			ft_putptr(void *ptr, t_print *count);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strjoin_gnl(char *str1, const char *str2);
void			*ft_memset(void *ptr, int input, size_t n);
void			ft_bzero(void *ptr, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t number, size_t size);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);

#endif
