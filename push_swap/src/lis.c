/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:25:42 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:16:46 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Determines if the rest of stack a is part of the lis array
 * 
 * @param data [t_data *] Pointer to data object
 * @return [int] 1 if yes, 0 if no
 */
static int	rest_is_lis(t_data *data)
{
	int	i;

	i = data->sp_a - 1;
	while (++i < data->argc - 1)
		if (!in_lis(data->lis, data->a[i]))
			return (0);
	return (1);
}

/**
 * @brief	Calculates the length of the longest increasing subsequence
 * 			and stores the index of the previous number in the lis index
 * 			array
 * 
 * @param data [t_data *] data struct
 */
void	find_lis(t_data *data)
{
	int	*lis_len;
	int	*lis_index;
	int	i;
	int	j;

	lis_len = ft_calloc(data->argc - 1, sizeof(int));
	lis_index = ft_calloc(data->argc - 1, sizeof(int));
	init_lis(data);
	set_arr(lis_len, 1, data->argc - 1);
	set_arr(lis_index, -1, data->argc - 1);
	j = data->sp_a - 1;
	while (++j < data->argc - 1)
	{
		i = data->sp_a - 1;
		while (++i < j)
		{
			if (data->a[j] > data->a[i] && lis_len[j] < lis_len[i] + 1)
			{
				lis_len[j] = lis_len[j] + 1;
				lis_index[j] = i;
			}
		}
	}
	build_lis(data, lis_len, lis_index);
}

/**
 * @brief	builds an array containing all numbers of the lis in sorted order
 * 			and frees the lis_len and lis_index arrays
 * 
 * @param data [t_data *]	data struct
 * @param lis_len [int *]	array containing the length of the lis ending at
 * 							that index
 * @param lis_index [int *]	array that contains the index of the previous number
 * 							in the lis ending at that index
 */
void	build_lis(t_data *data, int *lis_len, int *lis_index)
{
	int	i;
	int	index;

	i = -1;
	while (++i < data->argc - 1)
	{
		if (lis_len[i] > data->lis->len)
		{
			data->lis->len = lis_len[i];
			index = i;
		}
	}
	data->lis->lis_arr = ft_calloc(data->lis->len, sizeof(int));
	i = data->lis->len;
	while (--i >= 0)
	{
		data->lis->lis_arr[i] = data->a[index];
		index = lis_index[index];
	}
	free(lis_len);
	free(lis_index);
}

/**
 * @brief pushes all numbers that dont belong to the lis to stack b
 * 
 * @param data [t_data *]	data struct
 */
void	push_lis(t_data *data)
{
	int	i;

	i = data->sp_a - 1;
	while (++i < data->argc - 1)
	{
		if (rest_is_lis(data))
			break ;
		if (in_lis(data->lis, data->a[data->sp_a]))
			ra(data);
		else
			pb(data);
	}
}
