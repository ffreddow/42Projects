/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:48:07 by fhenrich          #+#    #+#             */
/*   Updated: 2021/12/21 10:40:43 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
