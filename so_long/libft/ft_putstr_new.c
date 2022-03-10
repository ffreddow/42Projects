/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:34:40 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/09 12:36:41 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
