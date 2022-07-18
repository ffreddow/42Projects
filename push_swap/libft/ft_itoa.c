/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:11:21 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/12 13:40:35 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long i)
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

/**
 * 
 */
static char	*ft_writestr_rev(char *str, long n, int is_negative)
{
	*str = '\0';
	str--;
	while (n / 10 != 0)
	{
		*str = (n % 10) + '0';
		str --;
		n /= 10;
	}
	*str = n + '0';
	if (is_negative == 1)
	{
		str--;
		*str = '-';
	}
	return (str);
}

/**
 * Converts intger to string
 * @param n [int] integer to convert
 * @return [char *] to the string it created
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		digit_num;
	int		is_negative;

	if (n == -2147483648)
		return (str = ft_substr("-2147483648", 0, 12));
	digit_num = ft_count_digits(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = n * -1;
		digit_num++;
	}
	str = (char *)ft_calloc(digit_num + 1, sizeof(char));
	if (!str)
		return (NULL);
	str += digit_num;
	str = ft_writestr_rev(str, n, is_negative);
	return (str);
}
