/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:33:15 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 16:50:24 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/**
 * Creates a new string with the defined characters cut away from the beginning 
 * and end of the input string
 * @param s1 [const char *] pointer to input string
 * @param set [const char *] pointer to set of characters to cut away
 * @return pointer to newly created string, NULL if an ERROR occured
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		start;
	size_t		end;

	start = 0;
	end = ft_strlen(s1);
	while (is_in_set(s1[start], set) == 1 && s1[start])
		start++;
	while (is_in_set(s1[end - 1], set) == 1 && start < end)
		end--;
	if (start < end)
		return (ft_substr(s1, start, end - start));
	else
		return (ft_calloc(1, sizeof(char)));
}
