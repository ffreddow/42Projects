/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:04:54 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:24:28 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * checks if an given character is alphanumerical
 * @param arg [int] the character to check
 * @return 1 if it is alphanumerical 0 if not
 */
int	ft_isalnum(int arg)
{
	return ((arg >= 48 && arg <= 57)
		|| (arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122));
}
