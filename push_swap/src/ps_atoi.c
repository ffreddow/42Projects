/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:48 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:14:18 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Atoi implementation but it returns a long
 * 
 * @param src [char *] String to convert
 * @return [long] Number contained in the string
 */
long	ps_atoi(char *src)
{
	char		first;
	long		ret;

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
