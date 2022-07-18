/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:42 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 17:21:59 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  combines two strings into a new one. This function frees the first
 * input string
 * @param str1 [char *] first input string. This one gets free'd!
 * @param str2 [const char *] second string
 * @return pointer to the newly created string
 */
char	*ft_strjoin_gnl(char *str1, const char *str2)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *) malloc((find_char(str1, 0) + find_char(str2, 0) + 1));
	if (str1)
	{
		while (str1[i])
		{
			ret[i] = str1[i];
			i++;
		}
		free(str1);
	}
	if (str2)
	{
		while (*str2)
		{
			ret[i++] = *str2;
			str2++;
		}
	}
	ret[i] = '\0';
	return (ret);
}

/**
 * Finds the index of the first appearence of a character
 * @param str [const char *] pointer to string to search in
 * @param c [unsigned char *]  character to search for
 * @return index of the first appearence of c in str
 */
int	find_char(const char *str, unsigned char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}
