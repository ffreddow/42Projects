/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:36:04 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/05 08:19:03 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_map *map, int i, int a)
{
	mlx_put_image_to_window(map->img->mlx, map->img->window, \
		map->img->background, a * 64, i * 64);
}

void	draw_player(t_map *map)
{
	mlx_put_image_to_window(map->img->mlx, map->img->window, map->img->player, \
		map->player->pos_x * 64, map->player->pos_y * 64);
}

void	draw_obj(t_map *map, int i, int a)
{
	if (map->map[i][a] == 'C')
		mlx_put_image_to_window(map->img->mlx, map->img->window, \
			map->img->collect, a * 64, i * 64);
	else if (map->map[i][a] == 'E')
		mlx_put_image_to_window(map->img->mlx, map->img->window, \
			map->img->exit, a * 64, i * 64);
	else if (map->map[i][a] == 'O')
		mlx_put_image_to_window(map->img->mlx, map->img->window, \
			map->img->open_exit, a * 64, i * 64);
	else if (map->map[i][a] == 'F')
		mlx_put_image_to_window(map->img->mlx, map->img->window, \
			map->img->collected, a * 64, i * 64);
	else if (map->map[i][a] == '1')
		mlx_put_image_to_window(map->img->mlx, map->img->window, \
			map->img->wall, a * 64, i * 64);
}
