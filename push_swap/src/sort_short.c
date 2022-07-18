/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:39:32 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:23:26 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorting of three elements hardcoded
 * 
 * @param data [t_data *] Pointer to data object
 */
static void	sort_three(t_data *data)
{
	if (data->argc - 1 == 1)
		return ;
	if (data->a[data->sp_a] > data->a[data->sp_a + 1] && \
		data->a[data->sp_a + 1] < data->a[data->sp_a + 2] \
		&& data->a[data->sp_a] > data->a[data->sp_a + 2])
		return ;
	if (data->a[data->sp_a] > data->a[data->sp_a + 1])
		sa(data);
	if (data->a[data->sp_a] < data->a[data->sp_a + 1] && \
		data->a[data->sp_a] < data->a[data->sp_a + 2] && \
		data->a[data->sp_a + 1] > data->a[data->sp_a + 2])
	{
		rra(data);
		sa(data);
	}
}

/**
 * @brief Sorting for a small stack
 * 
 * @param data [t_data *] Pointer to data object
 */
void	sort_short(t_data *data)
{
	if (data->argc == 4)
		sort_three(data);
	if (data->argc == 6)
	{
		pb(data);
		pb(data);
		sort_three(data);
	}
}
