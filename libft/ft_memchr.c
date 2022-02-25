/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:26:17 by fhenrich          #+#    #+#             */
/*   Updated: 2022/02/06 20:12:07 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
