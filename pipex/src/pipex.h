/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 08:32:27 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/22 16:21:59 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "../libft/libft.h"

/**
 * Struct to safe all needed data in
 * @param curren_command [int] the number of commands build
 * @param argc [int] number of arguments passed to the program
 * @param inputfd [int] fd of the input file
 * @param output_fd [int] fd to the output file
 * @param is_absolute [int] control variable to check if the cmd
 * string needs to be freed
 * @param cmd [char *] string containing the next command to run
 * @param args [char **] array of strings containing the arguments
 * for the next command
 * @param argv [char **] argument vector passed to the program
 * @param path [cahr **] array containing all pathes currently stored
 * int the PATH variable
 * @param envp [char *] vector to the environment variables
 */
typedef struct s_data
{
	int		current_command;
	int		argc;
	int		inputfd;
	int		outputfd;
	int		is_absolute;
	char	*cmd;
	char	**args;
	char	**argv;
	char	**path;
	char	**envp;
}	t_data;

int		*create_pipes(int num_pipes);
int		open_file(char **argv, int i);
char	**get_path(char **envp);
void	init_struct(t_data *data, int argc, char **argv, char **envp);
void	build_command(t_data *data);
void	child_process(t_data *data, int *fd);
void	set_fd(t_data *data, int *fd);
void	close_fds(t_data *data, int *fd);
void	free_struct(t_data *data);
void	free_args(t_data *data);

#endif