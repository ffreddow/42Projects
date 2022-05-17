/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:13 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/05 10:30:54 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_cleanup(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	visual_cleanup(t_map *map)
{
	t_images	*img;

	img = map->img;
	mlx_destroy_image(img->mlx, img->background);
	mlx_destroy_image(img->mlx, img->player);
	mlx_destroy_image(img->mlx, img->exit);
	mlx_destroy_image(img->mlx, img->open_exit);
	mlx_destroy_image(img->mlx, img->collect);
	mlx_destroy_image(img->mlx, img->collected);
	mlx_destroy_image(img->mlx, img->wall);
	mlx_clear_window(img->mlx, img->window);
	mlx_destroy_window(img->mlx, img->window);
}

int	cleanup(t_map *map)
{
	map_cleanup(map);
	visual_cleanup(map);
	free(map->img);
	free(map->player);
	free(map);
	exit(0);
	return (0);
}
