/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:26:17 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:21:05 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * searches for a specific character in memory
 * @param str [const void *] pointer to memory to search in
 * @param c [int] character to search for
 * @param n [size_t] number of bytes to iterate through
 * @return first byte after the character, NULL if it not found
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;

	i = 0;
	string = (unsigned char *)str;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return (string + i);
		i++;
	}
	return (NULL);
}
