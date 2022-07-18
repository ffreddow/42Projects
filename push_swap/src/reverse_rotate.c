/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:09:16 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:19:13 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Implementation of rra command
 * 
 * @param data [t_data *] Pointer to data struct
 */
void	rra(t_data *data)
{
	int	i;
	int	tmp;

	i = data->argc - 1;
	tmp = data->a[data->argc - 2];
	while (--i > data->sp_a)
	{
		data->a[i] = data->a[i - 1];
	}
	data->a[data->sp_a] = tmp;
	ft_printf("rra\n");
}

/**
 * @brief Implementation of the rrb command
 * 
 * @param data [t_data *] Pointer to data struct
 */
void	rrb(t_data *data)
{
	int	i;
	int	tmp;

	i = data->argc - 1;
	tmp = data->b[data->argc - 2];
	while (--i > data->sp_b)
	{
		data->b[i] = data->b[i - 1];
	}
	data->b[data->sp_b] = tmp;
	ft_printf("rrb\n");
}

/**
 * @brief Implementation of the rrr command
 * 
 * @param data [t_data *] Pointer to data struct
 */
void	rrr(t_data *data)
{
	int	i;
	int	tmp;

	i = data->argc - 1;
	tmp = data->a[data->argc - 2];
	while (--i > data->sp_a)
	{
		data->a[i] = data->a[i - 1];
	}
	data->a[data->sp_a] = tmp;
	i = data->argc - 1;
	tmp = data->b[data->argc - 2];
	while (--i > data->sp_b)
	{
		data->b[i] = data->b[i - 1];
	}
	data->b[data->sp_b] = tmp;
	ft_printf("rrr\n");
}
