/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:11:54 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 12:59:08 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_atoi takes an array and converts it into an integer.
 * It cuts away every non-printable characters infront of the number
 * @param src [char *] string to convert
 * @return the number contained in src as int
 */
int	ft_atoi(const char *src)
{
	char	first;
	int		ret;

	first = 0;
	ret = 0;
	while ((!ft_isprint(*src) && *src != '\e' && *src != '\0') || *src == ' ')
	{
		src++;
	}
	if ((*src == '-' || *src == '+') && ft_isdigit(*(src + 1)))
	{
		first = *src;
		src++;
	}
	while (ft_isdigit(*src) && *src != '\0')
	{
		ret = ret * 10 + (*src - 48);
		src++;
	}
	if (first == '-')
		ret = ret - 2 * ret;
	return (ret);
}
