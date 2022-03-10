/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:13:41 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/09 12:37:46 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
