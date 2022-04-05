/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:36:15 by fhenrich          #+#    #+#             */
/*   Updated: 2022/03/23 09:49:59 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	move_counter;
}	t_player;

typedef struct s_object
{
	int			type;
	int			pos_x;
	int			pos_y;
	t_object	*next;
}	t_object;

typedef struct s_map
{
	char		**map;
	int			num_player;
	int			num_exit;
	int			num_collect;
	t_player	*player;
}	t_map;

int		init_map(t_map *map, char *mapfile);
int		array_len(char **arr);
int		check_walls(char **map);
int		verify_map(t_map *map);
int		check_tiles(t_map *map, int i, int a);
char	**get_map(char *mapfile);
void	map_cleanup(t_map *map);

#endif