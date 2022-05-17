/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 06:11:56 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:31:53 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * sets n bytes of memory pointed to by ptr to input
 * @param ptr [void *] pointer to memory to overwrite
 * @param input [int] value to set memory to
 * @param n [size_t] number of bytes to write
 */
void	*ft_memset(void *ptr, int input, size_t n)
{
	unsigned char	*data;

	data = ptr;
	while (n > 0)
	{
		*data = input;
		data = data + 1;
		n--;
	}
	return (ptr);
}
