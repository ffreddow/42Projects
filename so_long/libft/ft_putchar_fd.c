/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:34:19 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 14:35:06 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * writes one character to the given filedescriptor
 * @param c [char] character to write
 * @param fd [int] filedescriptor to write to
 * @return none
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
