/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:52:32 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/15 15:32:41 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief	calculates the number of rotaion steps to bring the number at index
 * 			i to the top
 * 
 * @param data [t_data *]	pointer to data object
 * @param i [int]	index to calculate
 * @return [int]	the number of rotations to bring the index to the top
 * 					of stack b
 */
int	steps_to_top(t_data *data, int i)
{
	int	stack_height;

	stack_height = data->argc - 1 - data->sp_b;
	if (i - data->sp_b - 1 <= stack_height / 2)
		return (i - data->sp_b);
	return (i - data->sp_b - stack_height);
}

/**
 * @brief Calculates the number of total steps needed to get to get
 * 			the chosen Numbers to top
 * 
 * @param dist [int *] Array of length 2 containing steps for stack a
 * 				at index 0 and steps for stack b at index 1
 * @return [int] Minimum of steps needed
 */
int	calc_steps(int *dist)
{
	if (dist[0] * dist[1] > 0)
	{
		if (positive(dist[0]) > positive(dist[1]))
			return (positive(dist[0]));
		return (positive(dist[1]));
	}
	return (positive(dist[0]) + positive(dist[1]));
}

/**
 * @brief Rotates both stacks in the same direction if it is
 * 			possible
 * 
 * @param data [t_data *] Pointer to data object
 * @param dist [int *] Array of length 2 containing the distances
 * 				to rotate
 */
void	rotate_both(t_data *data, int *dist)
{
	if (dist[0] * dist[1] > 0)
	{
		if (dist[0] > 0)
		{	
			while (dist[0] != 0 && dist[1] != 0)
			{
				rr(data);
				dist[0]--;
				dist[1]--;
			}
		}
		else
		{
			while (dist[0] != 0 && dist[1] != 0)
			{
				rrr(data);
				dist[0]++;
				dist[1]++;
			}
		}
	}
}

/**
 * @brief Finds the 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int	find_spot(t_data *data, int num)
{
	int	i;
	int	stack_height;

	if (data->a[data->argc - 2] < num && data->a[data->sp_a] > num)
		return (0);
	i = data->sp_a - 1;
	stack_height = data->argc - 1 - data->sp_a;
	while (++i < data->argc - 2)
	{
		if (data->a[i] < num && data->a[i + 1] > num)
		{
			if (i - data->sp_a <= stack_height / 2)
				return (i - data->sp_a + 1);
			return (i - data->sp_a + 1 - stack_height);
		}
	}
	return (max_pos_a(data));
}

int	max_pos_a(t_data *data)
{
	int	i;
	int	max;
	int	max_index;
	int	stack_height;

	stack_height = data->argc - 1 - data->sp_a;
	i = data->sp_a;
	max = data->a[data->sp_a];
	max_index = data->sp_a;
	while (++i < data->argc - 1)
	{
		if (data->a[i] > max)
		{
			max = data->a[i];
			max_index = i;
		}
	}
	if (max_index - data->sp_a <= stack_height / 2)
		return (max_index - data->sp_a + 1);
	return ((stack_height - (max_index - data->sp_a + 1)) * -1);
}
