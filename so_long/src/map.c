/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:16:24 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/23 09:43:01 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_map	*map, char *mapfile)
{
	int	ret;

	map->map = get_map(mapfile);
	if (!map->map)
		return (-1);
	map->num_player = 0;
	map->num_exit = 0;
	map->num_collect = 0;
	ret = verify_map(map);
	if (ret == -1)
		ft_printf("Incomplete Walls\n");
	else if (ret == -2)
		ft_printf("Wrong number of collectables\n");
	else if (ret == -3)
		ft_printf("Wrong number of exits\n");
	else if (ret == -4)
		ft_printf("Wrong number of players\n");
	else if (ret == -5)
		ft_printf("unknown tiles\n");
	if (ret != 0)
		return (-1);
	ft_printf("Map ok\n");
	return (0);
}

char	**get_map(char *mapfile)
{
	char		**map;
	char		*tmp;
	char		*tmp2;
	const int	fd = open(ft_strjoin("maps/", mapfile), O_RDONLY);

	if (fd < 0)
		return (0);
	tmp = 0;
	while (1)
	{
		tmp2 = get_next_line(fd);
		if (!tmp2)
			break ;
		tmp = ft_strjoin_gnl(tmp, tmp2);
		free(tmp2);
	}
	close(fd);
	map = ft_split(tmp, '\n');
	free(tmp);
	return (map);
}

int	verify_map(t_map *map)
{
	int			i;

	if (check_walls(map->map))
		return (-1);
	i = check_tiles(map, 0, 0);
	if (map->num_collect < 1)
		return (-2);
	if (map->num_exit != 1)
		return (-3);
	if (map->num_player != 1)
		return (-4);
	if (i != 0)
		return (i);
	return (0);
}

int	check_tiles(t_map *map, int i, int a)
{
	while (map->map[i])
	{
		a = 0;
		while (map->map[i][a])
		{
			if (map->map[i][a] == 'C')
				map->num_collect += 1;
			else if (map->map[i][a] == 'P')
				map->num_player += 1;
			else if (map->map[i][a] == 'E')
				map->num_exit += 1;
			else if (map->map[i][a] == '1')
				map->num_exit = map->num_exit;
			else if (map->map[i][a] == '0')
				map->num_exit = map->num_exit;
			else
				return (-5);
			a++;
		}
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int			i;
	int			a;
	int			ret;
	const int	arr_len = array_len(map);
	const int	len = ft_strlen(map[i]);

	i = 0;
	while (i < arr_len)
	{
		a = 0;
		if (len != ft_strlen(map[i]))
			return (-1);
		if (i == 0 || i == arr_len - 1)
		{
			while (map[i][a] == '1')
				a++;
			if (a != len)
				return (-1);
		}
		else if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
