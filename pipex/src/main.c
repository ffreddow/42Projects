/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:36:01 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/22 12:40:46 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * The main function of the pipex program. It starts the initialisation
 * functions, creates all child processes and frees everything
 */
int	main(int argc, char *argv[], char *envp[])
{
	int		*fd;
	t_data	*data;

	if (argc < 5)
	{
		ft_printf("You got %i arguments but min 4 are needed\n", argc - 1);
		exit(0);
	}
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		perror("Error");
		exit(1);
	}
	init_struct(data, argc, argv, envp);
	fd = create_pipes(data->argc - 4);
	while (data->current_command + 3 < argc)
	{
		build_command(data);
		if (fork() == 0)
			child_process(data, fd);
	}
	close_fds(data, fd);
	free_struct(data);
	return (0);
}

/**
 * Initialises the data struct
 * @param data [t_data *] pointer to the data struct
 * @param argc [int] number of parameters passed to the program
 * @param argv [char **] array of pointers to the input parameters
 * passed to the program
 * @param envp [char **] array of pointers to env variables
 */
void	init_struct(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->current_command = 0;
	data->inputfd = open_file(argv, 0);
	data->outputfd = open_file(argv, 1);
	data->path = get_path(envp);
	data->envp = envp;
	data->is_absolute = 0;
}

/**
 * Gets called at the end of the program and frees everything inside
 * the data struct
 * @param data [t_data *] pointer to the data struct
 */
void	free_struct(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i])
		free(data->path[i++]);
	free_args(data);
	free(data->path);
	free(data);
}
