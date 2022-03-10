/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:40:16 by fhenrich          #+#    #+#             */
/*   Updated: 2022/02/06 20:07:52 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*c;

	c = (unsigned char *) ptr;
	if (!ptr)
		return ;
	i = 0;
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
}
