/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:42:01 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:26:26 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * copies n bytes from src to dest
 * @param dest [void *] pointer to destination memory
 * @param src [const void *] pointer to source memory
 * @param n [size_t] number of bytes to copy
 * @return pointer to destination memory
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*des;
	unsigned char	*source;

	source = (unsigned char *) src;
	des = (unsigned char *) dest;
	while (n-- > 0)
	{
		*des = *source;
		des++;
		source++;
	}
	return (dest);
}
