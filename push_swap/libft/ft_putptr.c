/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:13:41 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 12:42:59 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes the adress contained in a pointer in hexadecimal
 * to STDOUT. This funtion is part of ft_printf.
 * @param ptr [void *] pointer to print
 * @param count [t_print *] pointer to ft_printf counter struct
 * @return none
 */
void	ft_putptr(void *ptr, t_print *count)
{
	if (!ptr)
	{
		ft_putstr("0x0", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_base((unsigned long)ptr, "0123456789abcdef", count);
}
