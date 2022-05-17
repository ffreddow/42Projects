/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:40:06 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/22 16:04:27 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Simple function that supstitutes the dup error
 * to shorten the set_fd function
 */
static void	dup_error(void)
{
	perror("Dup");
	exit(1);
}

/**
 * the function that gets called in each child process
 * @param data [t_data *] pointer to data struct
 * @param fd [int *] array containing pipe fds
 */
void	child_process(t_data *data, int *fd)
{
	set_fd(data, fd);
	close_fds(data, fd);
	execve(data->cmd, data->args, 0);
	perror(data->args[0]);
	free_struct(data);
	exit(1);
}

/**
 * redirects the std in and out to the in/out file or a pipe
*/
void	set_fd(t_data *data, int *fd)
{
	if (data->current_command == 1)
	{
		if (dup2(data->inputfd, STDIN_FILENO) == -1)
			dup_error();
	}
	else
	{
		if (dup2(fd[(data->current_command - 2) * 2], STDIN_FILENO) == -1)
			dup_error();
	}
	if (data->current_command + 3 == data->argc)
	{
		if (dup2(data->outputfd, STDOUT_FILENO) == -1)
			dup_error();
	}
	else
	{
		if (dup2(fd[(data->current_command - 1) * 2 + 1], STDOUT_FILENO) == -1)
			dup_error();
	}
}

/**
 * creates pipes and stores them into an array
 * @param num_pipes [int] number of pipes to create
 * @return array of fds
 */
int	*create_pipes(int num_pipes)
{
	int	i;
	int	*fd;

	i = 0;
	fd = (int *)ft_calloc(num_pipes * 2, sizeof(int));
	while (i < num_pipes)
	{
		if (pipe(fd + (2 * i)) == -1)
		{
			perror("Pipe");
			exit(1);
		}
		i++;
	}
	return (fd);
}

/**
 * closes all open fds
 * @param data [t_data *] pointer to data struct
 * @param fd [int *] array of fds
 */
void	close_fds(t_data *data, int *fd)
{
	int	i;

	i = 0;
	while (i < (data->argc -4) * 2)
		if (close(fd[i++]) == -1)
			perror("Close Pipes");
	if (close(data->inputfd) == -1)
		perror("Close Input");
	if (close(data->outputfd) == -1)
		perror("Close Output");
	free(fd);
}
