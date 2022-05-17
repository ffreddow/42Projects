/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:36:01 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/06 08:27:13 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifdef __linux__

int	main(int argc, char *argv[])
{
	t_map	*map;
	char	*mapfile;

	if (argc != 2)
	{
		ft_printf("False number of arguments\n");
		return (0);
	}
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (-1);
	mapfile = ft_strjoin("maps/", argv[1]);
	if (init_map(map, mapfile) != 0)
		return (0);
	free(mapfile);
	init_visuals(map);
	init_window(map);
	mlx_key_hook(map->img->window, get_key_linux, (void *)map);
	mlx_hook(map->img->window, 17, 0, cleanup, (t_map *)map);
	mlx_loop(map->img->mlx);
	return (0);
}

#else

int	main(int argc, char *argv[])
{
	t_map	*map;
	char	*mapfile;

	if (argc != 2)
	{
		ft_printf("False number of arguments\n");
		return (0);
	}
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (-1);
	mapfile = ft_strjoin("maps/", argv[1]);
	if (init_map(map, mapfile) != 0)
		return (0);
	free(mapfile);
	init_visuals(map);
	init_window(map);
	mlx_key_hook(map->img->window, get_key, (void *)map);
	mlx_hook(map->img->window, 17, 0, cleanup, (t_map *)map);
	mlx_loop(map->img->mlx);
	return (0);
}

#endif