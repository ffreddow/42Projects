/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:40:16 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:18:23 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero sets the memory ptr points to to zero
 * @param ptr [void *] pointer to the memory
 * @param size [size_t] size to zero in bytes
 * @return none
 */
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
