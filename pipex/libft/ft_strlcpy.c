/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:47:18 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 13:46:01 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies n characters from source string to destination string
 * @param dst [char *] pointer to destination string
 * @param src [const char *] pointer to source string
 * @param n [size_t] characters to write
 * @return length of source string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	const char	*source = src;

	if (n > 0)
	{
		n--;
		while (n > 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			n--;
		}
		*dst = '\0';
	}
	return ((size_t)ft_strlen(source));
}
