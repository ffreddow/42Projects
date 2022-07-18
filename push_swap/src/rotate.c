/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:48:35 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:21:06 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Implementation of the ra command
 * 
 * @param data [t_data *] Pointer to data object
 */
void	ra(t_data *data)
{
	int	i;
	int	tmp;

	i = data->sp_a - 1;
	tmp = data->a[data->sp_a];
	while (++i < data->argc - 2)
	{
		data->a[i] = data->a[i + 1];
	}
	data->a[data->argc - 2] = tmp;
	ft_printf("ra\n");
}

/**
 * @brief Implementation of the rb command
 * 
 * @param data [t_data *] Pointer to data object
 */
void	rb(t_data *data)
{
	int	i;
	int	tmp;

	i = data->sp_b - 1;
	tmp = data->b[data->sp_b];
	while (++i < data->argc - 2)
	{
		data->b[i] = data->b[i + 1];
	}
	data->b[data->argc - 2] = tmp;
	ft_printf("rb\n");
}

/**
 * @brief Implementation of the rr command
 * 
 * @param data [[t_data *] Pointer to data object
 */
void	rr(t_data *data)
{
	int	i;
	int	tmp;

	i = data->sp_a - 1;
	tmp = data->a[data->sp_a];
	while (++i < data->argc - 2)
	{
		data->a[i] = data->a[i + 1];
	}
	data->a[data->argc - 2] = tmp;
	i = data->sp_b - 1;
	tmp = data->b[data->sp_b];
	while (++i < data->argc - 2)
	{
		data->b[i] = data->b[i + 1];
	}
	data->b[data->argc - 2] = tmp;
	ft_printf("rr\n");
}
