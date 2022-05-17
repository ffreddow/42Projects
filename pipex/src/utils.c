/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:48:26 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/25 11:13:01 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * frees the array of argument strings and the cmd string
 * @param data [t_data *] pointer to data struct
 */
void	free_args(t_data *data)
{
	int	i;

	i = 0;
	if (data->args)
	{
		while (data->args[i])
			free(data->args[i++]);
		free(data->args);
	}
	if (data->cmd && !data->is_absolute)
		free(data->cmd);
}

/**
 * opens fds to the input or output file
 * @param argv [char **] the argument vector passed to the program
 * @param i [int] the file to open
 * @return the fd to the opened file
 */
int	open_file(char **argv, int i)
{
	int	a;
	int	fd;

	a = 0;
	if (i == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Input file");
			exit(1);
		}
		return (fd);
	}
	while (argv[a])
		a++;
	if (!access(argv[a - 1], W_OK))
		unlink(argv[a - 1]);
	fd = open(argv[a - 1], O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		perror("Output file");
		exit(1);
	}
	return (fd);
}

/**
 * Filters all pathes out of the env variables
 * @param envp [char **] env variables passed to the program
 * @return array of strings, each containing one path
 */
char	**get_path(char **envp)
{
	int		i;
	char	*tmp;
	char	**ret;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	tmp = ft_strtrim(envp[i], "PATH=");
	ret = ft_split(tmp, ':');
	free(tmp);
	return (ret);
}

/**
 * searches for the right path in the path array and stores it into
 * the cmd string in the data struct
 * @param data [t_data *] pointer to data struct
 */
void	build_command(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	free_args(data);
	data->args = ft_split(data->argv[data->current_command + 2], ' ');
	if (!access(data->args[0], X_OK))
	{
		data->cmd = data->args[0];
		data->current_command++;
		data->is_absolute = 1;
		return ;
	}
	tmp = ft_strjoin("/", data->args[0]);
	while (1)
	{
		data->cmd = ft_strjoin(data->path[i++], tmp);
		if (!access(data->cmd, X_OK) || !data->path[i])
			break ;
		free(data->cmd);
	}
	data->is_absolute = 0;
	free(tmp);
	data->current_command++;
}
