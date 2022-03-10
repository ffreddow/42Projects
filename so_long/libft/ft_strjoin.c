/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:02:03 by fhenrich          #+#    #+#             */
/*   Updated: 2021/11/30 21:32:29 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*ret;
	char	*start;

	ret = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	start = ret;
	while (*str1 != '\0')
	{
		*start = *str1;
		str1++;
		start++;
	}
	while (*str2 != '\0')
	{
		*start = *str2;
		str2++;
		start++;
	}
	*start = '\0';
	return (ret);
}
