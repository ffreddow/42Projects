/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:38:56 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:29:28 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * checks if the given character is a digit
 * @param arg [int] character to check
 * @return 1 if true 0 if false
 */
int	ft_isdigit(int arg)
{
	return (arg >= 48 && arg <= 57);
}
