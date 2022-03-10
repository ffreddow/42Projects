/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:11:52 by fhenrich          #+#    #+#             */
/*   Updated: 2021/11/30 18:41:11 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	const unsigned int	str2_len = ft_strlen(str2);

	if (*str2 == '\0')
		return ((char *)str1);
	while (n > 0 && *str1 != '\0')
	{
		if (ft_strncmp(str1, str2, str2_len) == 0 && str2_len <= n)
		{
			return ((char *)str1);
		}
		str1++;
		n--;
	}
	return (0);
}
