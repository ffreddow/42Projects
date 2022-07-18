/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:00:41 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 13:44:36 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * A recode of the strlcat function.
 * It appends n - length of destination string characters
 * of the source string to the destination string, guarantying
 * that it will be NULL terminated
 * @param dest [char *] pointer to destination string
 * @param src [const char *] pointer to source string
 * @param n [size_t] total characters to write to dest
 * @return number of bytes written
 */
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	const size_t	source_len = ft_strlen(src);
	const size_t	dest_len = ft_strlen(dest);

	if (n == 0)
		return (source_len);
	if (n <= dest_len)
		return (n + source_len);
	else
	{
		dest += dest_len;
		n -= dest_len + 1;
		while (n-- > 0 && *src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
		}
		*dest = '\0';
	}
	return (dest_len + source_len);
}
