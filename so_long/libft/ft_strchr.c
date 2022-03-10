/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:45:34 by fhenrich          #+#    #+#             */
/*   Updated: 2021/12/21 10:36:31 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (c < 256 && c >= 0)
	{
		while (*str != c)
		{
			if (*str == '\0')
				return (NULL);
			str++;
		}
		return ((char *)str);
	}
	return ((char *)str);
}
