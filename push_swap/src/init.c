/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:13:23 by fhenrich          #+#    #+#             */
/*   Updated: 2022/06/09 13:26:21 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * transforms array of the strings given to the program
 * into an array of integers and checks for errors
 * @param data [t_data *] pointer to the data struct containing
 * all the necessary data
 */
void	get_stack(t_data *data)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < data->argc - 1)
	{
		if (!check_num(data->argv[i + 1]))
			error_handler(data);
		tmp = ps_atoi(data->argv[i + 1]);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_handler(data);
		data->a[i] = (int) tmp;
		i++;
	}
	check_sorted(data, 0);
	check_duplicates(data);
}

/**
 * checks if the string contains only ascii digits
 * @param s [char *] string to check
 * @return 1 if true, 0 if false
 */
int	check_num(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-')
			return (0);
	}
	return (1);
}

/**
 * checks for duplicates in the input
 * @param data [t_data *] pointer to data struct
 */
void	check_duplicates(t_data *data)
{
	int	i;
	int	check;
	int	start;

	start = 0;
	while (start < data->argc - 2)
	{
		i = start++;
		check = data->a[i++];
		while (i < data->argc - 1)
		{
			if (data->a[i++] == check)
				error_handler(data);
		}
	}
}

/**
 * checks if stack a is sorted, if true the function will
 * exit the program. If false the funtion will return
 * @param data [t_data *] pointer to data array
 * @param mode [int] defines the operating mode of this function
 * @return if mode is 1 it will return 1 if sorted and 0 if unsorted
 */
int	check_sorted(t_data *data, int mode)
{
	int	i;

	i = -1;
	if (!mode)
	{
		while (++i < data->argc - 2)
		{
			if (data->a[i] >= data->a[i + 1])
				return (0);
		}
		quit(data, 0);
	}
	return (1);
}

/**
 * initialises data struct
 * @param argc [int] number of parameters passed to program
 * @param argv[char **] array of parameters passed to program
 */
t_data	*init_struct(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		error_handler(data);
	data->a = ft_calloc(argc, sizeof(int));
	if (!data->a)
		error_handler(data);
	data->b = ft_calloc(argc, sizeof(int));
	if (!data->b)
		error_handler(data);
	data->argc = argc;
	data->argv = argv;
	data->sp_a = 0;
	data->sp_b = argc - 1;
	return (data);
}
