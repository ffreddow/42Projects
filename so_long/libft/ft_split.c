/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:25:03 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/21 11:20:00 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Component of ft_split. Counts the ammount of substrings needed.
 */
static size_t	ft_countsplits(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
		if (*s != c && ++i)
			while (*s && *s++ != c)
				continue ;
	else
		s++;
	return (i);
}

/**
 * Splits the input string at every appearence of the character c
 * and creates a new string containing the snippet until the next 
 * appearence
 * @param s [char *] pointer to the input string
 * @param c [char] divider character
 * @return array of pointers to the created splits, NULL if an ERROR occured
 */
char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;

	ret = (char **) ft_calloc(ft_countsplits(s, (int) c) + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!ft_strchr(s, c))
			{
				ret[i++] = ft_substr(s, 0, ft_strlen(s));
				break ;
			}
			ret[i++] = ft_substr(s, 0, ft_strchr(s, (int) c) - s);
			s = ft_strchr(s, (int) c);
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}
