/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:41:00 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 17:09:10 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts uppercase ascii characters into lowercase
 * @param arg [int] character to convert
 * @return the lowercase character, the input character if it is not ascii
 * uppercase
 */
int	ft_tolower(int arg)
{
	if (arg >= 65 && arg <= 90)
	{
		return (arg + 32);
	}
	return (arg);
}
