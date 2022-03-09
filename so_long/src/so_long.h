/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:36:15 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/09 18:24:33 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define NOOP

# include "mlx.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	move_counter;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		num_player;
	int		num_exit;
	int		num_collect;
}	t_map;

int		init_map(t_map *map, char *mapfile);
int		array_len(char **arr);
int		check_walls(char **map, int len);
int		verify_map(t_map *map);
int		check_tile(t_map *map, int i, int a);
char	**get_map(char *mapfile);

#endif