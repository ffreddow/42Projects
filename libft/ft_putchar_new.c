/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:25:51 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:40:59 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * this function is used by ft_printf to print out one character
 * to STDOUT
 * @param c [cahr] character to print
 * @param count [t_print]
 * @return none
 */
void	ft_putchar(char c, t_print *count)
{
	write(1, &c, 1);
	if (count)
		count->total_len += 1;
}
