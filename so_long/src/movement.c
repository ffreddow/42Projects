/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:09:42 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/24 16:50:03 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	const int	pos_x = map->player->pos_x;
	const int	pos_y = map->player->pos_y;

	if (map->map[pos_y - 1][pos_x] != '1')
	{
		map->player->pos_y = pos_y - 1;
		map->player->move_counter += 1;
	}
}

void	move_down(t_map *map)
{
	const int	pos_x = map->player->pos_x;
	const int	pos_y = map->player->pos_y;

	if (map->map[pos_y + 1][pos_x] != '1')
	{
		map->player->pos_y = pos_y + 1;
		map->player->move_counter += 1;
	}
}

void	move_left(t_map *map)
{
	const int	pos_x = map->player->pos_x;
	const int	pos_y = map->player->pos_y;

	if (map->map[pos_y][pos_x - 1] != '1')
	{
		map->player->pos_x = pos_x - 1;
		map->player->move_counter += 1;
	}
}

void	move_right(t_map *map)
{
	const int	pos_x = map->player->pos_x;
	const int	pos_y = map->player->pos_y;

	if (map->map[pos_y][pos_x + 1] != '1')
	{
		map->player->pos_x = pos_x + 1;
		map->player->move_counter += 1;
	}
}
