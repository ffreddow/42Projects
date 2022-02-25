/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:42:01 by fhenrich          #+#    #+#             */
/*   Updated: 2022/01/29 16:27:30 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
