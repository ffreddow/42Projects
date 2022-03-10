/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:36:01 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/10 13:11:10 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*img;
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("False number of arguments\n");
		return (0);
	}
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (-1);
	if (init_map(map, argv[1]) != 0)
		return (0);
	map_cleanup(map);
	return (0);
}
