/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:21:39 by fhenrich          #+#    #+#             */
/*   Updated: 2022/06/14 14:07:16 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * rotates the smallest number of the stack to the top
 * 
 * @param data [t_data *] pointer to the data struct
 */
void	smallest_to_top(t_data *data)
{
	int	i;
	int	smallest_index;

	i = data->sp_a - 1;
	smallest_index = data->sp_a;
	while (++i < data->argc - 1)
		if (data->a[i] < data->a[smallest_index])
			smallest_index = i;
	smallest_index -= data->sp_a;
	if (smallest_index <= (data->argc - 1 - data->sp_a) / 2)
		while (smallest_index-- != 0)
			ra(data);
	else
		while (smallest_index++ != data->argc - 1 - data->sp_a)
			rra(data);
}

/**
 * @brief rotates both stacks to the right position and pushes b to a
 * 
 * @param data [t_data *] pointer to data struct
 */
void	push_best(t_data *data)
{
	int	*dist;

	dist = find_best_push(data);
	rotate_both(data, dist);
	if (dist[0] > 0)
		while (dist[0]--)
			ra(data);
	else if (dist[0] < 0)
		while (dist[0]++)
			rra(data);
	if (dist[1] > 0)
		while (dist[1]--)
			rb(data);
	else if (dist[1] < 0)
		while (dist[1]++)
			rrb(data);
	free(dist);
	pa(data);
}

int	*find_best_push(t_data *data)
{
	int	i;
	int	steps;
	int	best_steps;
	int	tmp[2];
	int	*best;

	best = ft_calloc(2, sizeof(int));
	best[0] = __INT_MAX__;
	best[1] = __INT_MAX__;
	best_steps = __INT_MAX__;
	i = data->sp_b - 1;
	while (++i < data->argc - 1)
	{
		tmp[0] = find_spot(data, data->b[i]);
		tmp[1] = steps_to_top(data, i);
		steps = calc_steps(tmp);
		if (steps < best_steps)
		{
			best_steps = steps;
			best[0] = tmp[0];
			best[1] = tmp[1];
		}
	}
	return (best);
}
