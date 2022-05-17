/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:31:42 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 13:15:14 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates through the input string and applies the given function
 * on every character
 * @param s [char *] pointer to input string
 * @param f [void *] pointer to function to apply
 * @return none
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
