/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:02:03 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 13:24:41 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Appends the second input string onto the first and
 * writes it into newly allocated memory
 * @param str1 [const char *] pointer to first input string
 * @param str2 [const char *] pointer to second string
 * @return pointer to newly created string, NULL if an ERROR occured
 */
char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		a;
	char	*ret;

	i = 0;
	a = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!ret)
		return (NULL);
	while (str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	while (str2[a])
		ret[i++] = str2[a++];
	ret[i] = 0;
	return (ret);
}
