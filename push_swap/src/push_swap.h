/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:53:26 by fhenrich          #+#    #+#             */
/*   Updated: 2022/06/09 14:54:52 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_lis
{
	int	len;
	int	*lis_arr;
}	t_lis;

typedef struct s_data
{
	int		*a;
	int		*b;
	int		argc;
	int		sp_a;
	int		sp_b;
	char	**argv;
	t_lis	*lis;
}	t_data;

int		check_num(char *s);
int		check_sorted(t_data *data, int mode);
int		in_lis(t_lis *lis, int num);
int		find_spot(t_data *data, int num);
int		steps_to_top(t_data *data, int i);
int		calc_steps(int *dist);
int		*find_best_push(t_data *data);
int		positive(int num);
int		max_pos_a(t_data *data);
long	ps_atoi(char *src);
void	quit(t_data *data, int code);
void	sort_short(t_data *data);
void	get_stack(t_data *data);
void	error_handler(t_data *data);
void	check_duplicates(t_data *data);
void	free_lis(t_lis *lis);
void	pa(t_data *data);
void	pb(t_data *data);
void	ss(t_data *data);
void	sb(t_data *data);
void	sa(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	ss(t_data *data);
void	rra(t_data *data);
void	rrr(t_data *data);
void	rrb(t_data *data);
void	rr(t_data *data);
void	smallest_to_top(t_data *data);
void	find_lis(t_data *data);
void	set_arr(int *arr, int set, int n);
void	init_lis(t_data *data);
void	build_lis(t_data *data, int *lis_len, int *lis_index);
void	push_lis(t_data *data);
void	rotate_both(t_data *data, int *dist);
void	push_best(t_data *data);
t_data	*init_struct(int argc, char **argv);

#endif
