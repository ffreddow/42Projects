/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:42 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/09 18:32:17 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(const char *str1, const char *str2)
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
		free((void *)str1);
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

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
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
