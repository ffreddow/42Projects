/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:22:47 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/14 16:09:24 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Implementation of the pa command
 * 
 * @param data [t_data *] Pointer to data object
 */
void	pa(t_data *data)
{
	if (data->sp_b == data->argc - 1)
		return ;
	data->a[--data->sp_a] = data->b[data->sp_b++];
	ft_printf("pa\n");
}

/**
 * @brief Implementation of the pb comman
 * 
 * @param data [t_data *] Pointer to data object
 */
void	pb(t_data *data)
{
	if (data->sp_a == data->argc - 1)
		return ;
	data->b[--data->sp_b] = data->a[data->sp_a++];
	ft_printf("pb\n");
}
