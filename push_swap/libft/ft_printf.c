/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:19:31 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:33:41 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_resolveidents(const char *s, t_print *args)
{
	if (*s == 'c')
		ft_putchar(va_arg(args->args, unsigned int), args);
	else if (*s == 's')
		ft_putstr(va_arg(args->args, char *), args);
	else if (*s == 'i' || *s == 'd')
		ft_base(va_arg(args->args, int), "0123456789", args);
	else if (*s == 'u')
		ft_base(va_arg(args->args, unsigned int), "0123456789", args);
	else if (*s == 'x')
		ft_base(va_arg(args->args, unsigned int), "0123456789abcdef", args);
	else if (*s == 'X')
		ft_base(va_arg(args->args, unsigned int), "0123456789ABCDEF", args);
	else if (*s == 'p')
		ft_putptr(va_arg(args->args, void *), args);
	else if (*s == '%')
		ft_putchar('%', args);
	s++;
	return (s);
}

/**
 * clone of the popular printf function
 * @param s [const char *] pointer to string to write
 * @return number of characters written
 */
int	ft_printf(const char *s, ...)
{
	t_print	*count;
	int		counter;

	count = (t_print *)malloc((sizeof(t_print)));
	if (!count)
		return (-1);
	count->total_len = 0;
	va_start(count->args, s);
	while (*s)
	{
		if (*s == '%')
			s = ft_resolveidents(++s, count);
		else
			ft_putchar(*s++, count);
	}
	va_end(count->args);
	counter = count->total_len;
	free(count);
	return (counter);
}
