/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:34:40 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 12:50:31 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function is part of ft_printf.
 * Writes the string str points to to STDOUT
 * @param str [char *] pointer to string to write
 * @param counter [t_print *] pointer to ft_printf counter struct
 * @return none
 */
void	ft_putstr(char *str, t_print *counter)
{
	if (!str)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		counter->total_len += 1;
		str++;
	}
}
