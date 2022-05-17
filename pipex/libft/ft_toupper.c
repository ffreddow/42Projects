/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:34:12 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 17:09:13 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts lowercase ascii characters into uppercase
 * @param arg [int] character to convert
 * @return the uppercase character, the input character if it is not ascii
 * lowercase
 */
int	ft_toupper(int arg)
{
	if (arg >= 97 && arg <= 122)
	{
		return (arg - 32);
	}
	return (arg);
}
