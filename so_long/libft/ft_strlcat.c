/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:00:41 by fhenrich          #+#    #+#             */
/*   Updated: 2021/12/17 18:34:20 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
