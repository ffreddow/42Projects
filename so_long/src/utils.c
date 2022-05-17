/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:42:07 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/05 10:56:29 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	get_key(int key, void *param)
{
	if (key == 13)
		move_up((t_map *)param);
	else if (key == 1)
		move_down((t_map *)param);
	else if (key == 0)
		move_left((t_map *)param);
	else if (key == 2)
		move_right((t_map *)param);
	else if (key == 53)
		cleanup((t_map *)param);
	player_check_tile((t_map *)param);
	update_window((t_map *)param);
	return (0);
}

int	get_key_linux(int key, void *param)
{
	if (key == 119)
		move_up((t_map *)param);
	else if (key == 115)
		move_down((t_map *)param);
	else if (key == 97)
		move_left((t_map *)param);
	else if (key == 100)
		move_right((t_map *)param);
	else if (key == 65307)
		cleanup((t_map *)param);
	player_check_tile((t_map *)param);
	update_window((t_map *)param);
	return (0);
}
