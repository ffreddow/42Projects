/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:35:05 by fhenrich          #+#    #+#             */
/*   Updated: 2021/12/21 11:39:29 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
