/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:33:04 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/05 08:30:48 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_visuals(t_map	*map)
{
	t_images	*img;

	img = (t_images *)ft_calloc(1, sizeof(t_images));
	if (!img)
		return (-1);
	img->size = 64;
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, map->size_x * 64, map->size_y * 64, \
		"so_long");
	img->background = mlx_xpm_file_to_image(img->mlx, "img/gras.xpm", \
		&img->size, &img->size);
	img->player = mlx_xpm_file_to_image(img->mlx, "img/player.xpm", &img->size, \
		&img->size);
	img->collect = mlx_xpm_file_to_image(img->mlx, "img/collectable.xpm", \
		&img->size, &img->size);
	img->collected = mlx_xpm_file_to_image(img->mlx, "img/collected.xpm", \
		&img->size, &img->size);
	img->exit = mlx_xpm_file_to_image(img->mlx, "img/exit_closed.xpm", \
		&img->size, &img->size);
	img->open_exit = mlx_xpm_file_to_image(img->mlx, "img/exit_open.xpm", \
		&img->size, &img->size);
	img->wall = mlx_xpm_file_to_image(img->mlx, "img/wall.xpm", \
		&img->size, &img->size);
	map->img = img;
	return (0);
}

int	init_window(t_map *map)
{
	update_window(map);
	return (0);
}

void	update_window(t_map *map)
{
	int			i;
	int			a;
	char		*num;

	i = 0;
	while (map->map[i])
	{
		a = 0;
		while (map->map[i][a])
		{
			draw_background(map, i, a);
			draw_obj(map, i, a);
			draw_player(map);
			a++;
		}
		i++;
	}
	num = ft_itoa(map->player->move_counter);
	mlx_string_put(map->img->mlx, map->img->window, 20, 20, 0xFF, \
		num);
	free(num);
}
