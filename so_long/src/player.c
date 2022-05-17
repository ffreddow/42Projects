/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:35:09 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/25 09:44:36 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_finish(t_map *map)
{
	int	i;
	int	a;

	i = 0;
	while (map->map[i])
	{
		a = 0;
		while (map->map[i][a])
		{
			if (map->map[i][a] == 'E')
				map->map[i][a] = 'O';
			a++;
		}
		i++;
	}
}

t_player	*create_player(int x, int y)
{
	t_player	*player;

	player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!player)
		return (0);
	player->pos_x = x;
	player->pos_y = y;
	player->move_counter = 0;
	return (player);
}

void	player_check_tile(t_map *map)
{
	const int	x = map->player->pos_x;
	const int	y = map->player->pos_y;

	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = 'F';
		map->num_collect -= 1;
	}
	if (map->map[y][x] == 'O')
		cleanup(map);
	if (map->num_collect == 0)
		set_finish(map);
}

void	get_player(t_map *map)
{
	int	i;
	int	a;

	i = 0;
	while (map->map[i])
	{
		a = 0;
		while (map->map[i][a])
		{
			if (map->map[i][a] == 'P')
				map->player = create_player(a, i);
			a++;
		}
		i++;
	}
}
