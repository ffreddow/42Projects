/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:45:13 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:33:50 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * checks if charater is printable
 * @param arg [int] character to check
 * @return 1 if true, 0 if false
 */
int	ft_isprint(int arg)
{
	return (arg >= 32 && arg <= 126);
}
