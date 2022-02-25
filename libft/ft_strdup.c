/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:40:45 by fhenrich          #+#    #+#             */
/*   Updated: 2022/01/11 13:59:00 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*str;
	char	*start;

	len = ft_strlen(src);
	str = (char *) malloc(sizeof(char) * (len + 1));
	start = str;
	while (len > 0)
	{
		*str = *src;
		str++;
		src++;
		len--;
	}
	*str = '\0';
	return (start);
}
