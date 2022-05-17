/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:36:15 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/05 10:42:22 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	move_counter;
}	t_player;

typedef struct s_images
{
	int		size;
	void	*exit;
	void	*open_exit;
	void	*background;
	void	*player;
	void	*collect;
	void	*collected;
	void	*wall;
	void	*window;
	void	*mlx;
}	t_images;

typedef struct s_map
{
	char		**map;
	int			num_player;
	int			num_exit;
	int			num_collect;
	int			size_x;
	int			size_y;
	t_player	*player;
	t_images	*img;
}	t_map;

int			init_map(t_map *map, char *mapfile);
int			array_len(char **arr);
int			check_walls(t_map *map);
int			verify_map(t_map *map);
int			check_tiles(t_map *map, int i, int a);
int			init_visuals(t_map	*map);
int			init_window(t_map *map);
int			cleanup(t_map *map);
int			get_key(int key, void *param);
int			get_key_linux(int key, void *param);
char		**get_map(char *mapfile);
void		map_cleanup(t_map *map);
void		get_player(t_map *map);
void		move_up(t_map *map);
void		move_down(t_map *map);
void		move_right(t_map *map);
void		move_left(t_map *map);
void		draw_background(t_map *map, int i, int a);
void		draw_player(t_map *map);
void		update_window(t_map *map);
void		draw_obj(t_map *map, int i, int a);
void		player_check_tile(t_map *map);
t_player	*create_player(int x, int y);

#endif