/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:39:24 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/09 12:37:23 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
