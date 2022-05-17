/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:40:45 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 13:12:30 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates the input string into newly allocated memory
 * @param src [const char *] pointer to input string
 * @return Pointer to the newly created string, NULL if an ERROR
 * occured. Notice that the output string will be empty if ther is
 * no input string
 */
char	*ft_strdup(const char *src)
{
	int		len;
	char	*str;
	char	*start;

	len = ft_strlen(src);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
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
