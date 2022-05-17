/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:51:32 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:24:42 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * compares n bytes of the memory pointed to by the input pointers
 * @param str1 [const void *] pointer one
 * @param str2 [const void *] pointer two
 * @param n [size_t] number of bytes to compare
 * @return the difference between the first mismatching bytes, NULL if both
 * are identical
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t					i;
	const unsigned char		*s1 = (const unsigned char *) str1;
	const unsigned char		*s2 = (const unsigned char *) str2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
