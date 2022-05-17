/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:47:56 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:30:09 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * the same functionality as ft_memcpy but this functions has 
 * protections for overlapping memory areas
 * @param dest [void *] pointer to memory to copy to
 * @param src [const void *] pointer to memory to copy from
 * @param n [size_t] number of bytes to copy
 * @return pointer to destination memory
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;

	if (!src || !dest)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
