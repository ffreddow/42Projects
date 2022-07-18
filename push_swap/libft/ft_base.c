/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:39:24 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:12:41 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_base is part of the ft_printf function.
 * It converts the given long double into a string with the defined base
 * and prints it to STDOUT
 * @param num [long double] number to convert
 * @param content [char *] string that contains every character of the
 * base in ascending order
 * @param counter [t_print *] struct used by ft_printf to count written
 * characters
 * @return none
 */
void	ft_base(long double num, char *content, t_print *counter)
{
	int	base;

	base = ft_strlen(content);
	if (num < 0)
	{
		ft_putchar('-', counter);
		num *= -1;
	}
	if (num >= base)
	{
		ft_base(num / base, content, counter);
		ft_putchar(*(content + ((unsigned long)num % base)), counter);
	}
	else if (num < base)
		ft_putchar(*(content + (unsigned long)num), counter);
}
