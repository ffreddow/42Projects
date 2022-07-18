/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:53:23 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/11 12:06:37 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		exit(1);
	data = init_struct(argc, argv);
	if (!data)
		error_handler(data);
	get_stack(data);
	if (data->argc < 7)
		sort_short(data);
	smallest_to_top(data);
	find_lis(data);
	push_lis(data);
	while (data->sp_b != data->argc - 1)
		push_best(data);
	smallest_to_top(data);
	free_lis(data->lis);
	quit(data, 0);
	return (0);
}
