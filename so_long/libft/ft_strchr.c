/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:45:34 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 13:03:50 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Seaches the input string for the first appearence of the
 * divider character
 * @param str [char *] pointer to input string
 * @param c [char] divider character
 * @return Pointer to the first appearence of c, pointer to start
 * of the string if c is not a char, NULL if c is not in str
 */
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
