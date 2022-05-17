/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:35:05 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 17:05:25 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates a part of the input string into a new string
 * @param s [const char *] pointer to input string
 * @param start [size_t] index of input string to start from
 * @param len [size_t] number of characters to duplicate
 * @return pointer to the newly created string
 */
char	*ft_substr(char const *s, size_t start, size_t len)
{
	char			*str;
	char			*ret;
	const size_t	src_len = (size_t)ft_strlen(s);

	if (len < src_len)
		ret = ft_calloc(len + 1, sizeof(char));
	else
		ret = ft_calloc(src_len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	str = ret;
	while (start-- > 0 && *s != '\0')
		s++;
	while (len-- > 0 && *s != '\0')
	{
		*str = *s;
		s++;
		str++;
	}
	return (ret);
}
