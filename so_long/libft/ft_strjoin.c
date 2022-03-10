/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:02:03 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/10 13:34:13 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		a;
	char	*ret;

	i = 0;
	a = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
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
