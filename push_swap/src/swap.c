/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:31:58 by fhenrich          #+#    #+#             */
/*   Updated: 2022/05/13 14:06:43 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	if (data->sp_a >= data->argc - 2)
		return ;
	tmp = data->a[data->sp_a];
	data->a[data->sp_a] = data->a[data->sp_a + 1];
	data->a[data->sp_a + 1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	int	tmp;

	if (data->sp_b >= data->argc - 2)
		return ;
	tmp = data->b[data->sp_b];
	data->b[data->sp_b] = data->b[data->sp_b + 1];
	data->b[data->sp_b + 1] = tmp;
	ft_printf("sa\n");
}

void	ss(t_data *data)
{
	int	tmp;

	if (data->sp_a >= data->argc - 2)
		return ;
	tmp = data->a[data->sp_a];
	data->a[data->sp_a] = data->a[data->sp_a + 1];
	data->a[data->sp_a + 1] = tmp;
	if (data->sp_b >= data->argc - 2)
		return ;
	tmp = data->b[data->sp_b];
	data->b[data->sp_b] = data->b[data->sp_b + 1];
	data->b[data->sp_b + 1] = tmp;
	ft_printf("ss\n");
}
