/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:32:29 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:25:40 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * checks if the given character is alphabetical
 * @param arg [int] character to check
 * @return 1 if it is aphabetical 0 if not
 */
int	ft_isalpha(int arg)
{
	if (arg >= 65 && arg <= 90)
	{
		return (1);
	}
	else if (arg >= 97 && arg <= 122)
	{
		return (2);
	}
	return (0);
}
