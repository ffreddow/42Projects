/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:38:05 by fhenrich          #+#    #+#             */
/*   Updated: 2022/05/31 14:00:34 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sets the first n indexes of an integer array to the given number
 * @param arr [int *] pointer to array
 * @param set [int] integer to set to
 * @param n [int] number of indexes to set
 */
void	set_arr(int *arr, int set, int n)
{
	while (--n != -1)
	{
		arr[n] = set;
	}
}

/**
 * @brief initialises the lis struct inside the data struct
 * 
 * @param data [t_data *] pointer to data struct
 */
void	init_lis(t_data *data)
{
	data->lis = ft_calloc(1, sizeof(t_lis));
	if (!data->lis)
		error_handler(data);
	data->lis->len = 1;
}

/**
 * @brief frees the lis struct
 * 
 * @param lis [t_lis *] pointer to lis struct
 */
void	free_lis(t_lis *lis)
{
	free(lis->lis_arr);
	free(lis);
}

/**
 * @brief checks if the provided struct is part of the lis
 * 
 * @param lis [t_lis *] pointer to the lis struct
 * @param num [int]	number to check
 * @return [int]	1 if the number is part of the lis
 * 					0 if the number is no part of the lis
 */
int	in_lis(t_lis *lis, int num)
{
	int	i;

	i = -1;
	while (++i < lis->len)
		if (lis->lis_arr[i] == num)
			return (1);
	return (0);
}
