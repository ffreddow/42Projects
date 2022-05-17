/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:31:19 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:28:26 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * checks if the given character is part of the ascii table
 * @param arg [int] character to check
 * @return 1 if it is part of the table 0 if not
 */
int	ft_isascii(int arg)
{
	return (arg >= 0 && arg <= 127);
}
