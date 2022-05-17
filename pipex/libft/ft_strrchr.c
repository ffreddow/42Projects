/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:48:07 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 14:16:28 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the las appearence of a character in the input string
 * @param str [const char *] pointer to input string
 * @param c [int] character to search for
 * @return pointer to last appearence of c, pointer to start if c is not a
 * character, pointer to the end of input string, NULL if c is not found
 */
char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = 0;
	if (c >= 256 || c < 0)
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == c)
			tmp = (char *) str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (tmp);
}
