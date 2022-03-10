/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 06:11:56 by fhenrich          #+#    #+#             */
/*   Updated: 2022/02/02 12:54:21 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
