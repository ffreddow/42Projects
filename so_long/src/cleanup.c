/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:10:13 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/10 13:10:31 by fhenrich         ###   ########.fr       */
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
	free(map);
}
