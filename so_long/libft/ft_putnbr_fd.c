/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:06:51 by fhenrich          #+#    #+#             */
/*   Updated: 2022/02/02 14:45:22 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_powerto(int n, int power)
{
	power--;
	while (power != 0)
	{
		n *= 10;
		power--;
	}
	return (n);
}

static int	ft_count_digits(int i)
{
	int	counter;

	counter = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i = i * -1;
	while (i > 0)
	{
		i /= 10;
		counter++;
	}
	return (counter);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		divider;
	char	tmp;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	divider = ft_powerto(1, ft_count_digits(n));
	while (divider != 0)
	{
		tmp = (n / divider) + '0';
		n = n - ((n / divider) * divider);
		divider = divider / 10;
		ft_putchar_fd(tmp, fd);
	}
}
