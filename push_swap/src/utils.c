/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:00:20 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:08:11 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * simple function to shorten the error handling in
 * other functions
 * @param data [t_data *] pointer to the data struct
 */
void	error_handler(t_data *data)
{
	ft_printf("Error\n");
	quit(data, 1);
}

/**
 * frees everything and exits the program
 * @param data [t_data *] pointer to data struct
 * @param code [int] the exit code to use
 */
void	quit(t_data *data, int code)
{
	if (data)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		free(data);
	}
	exit(code);
}

/**
 * @brief	turns any integer to positive
 * 
 * @param num [int] number to turn
 * @return [int] positive value of num
 */
int	positive(int num)
{
	if (num > 0)
		return (num);
	return (num * -1);
}
