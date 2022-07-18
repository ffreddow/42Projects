/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:22:43 by fhenrich          #+#    #+#             */
/*   Updated: 2022/04/13 17:34:38 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Submodule of get_next_line. Reads the given filedescriptor
 * into file until it detects a new line or end of file inside
 * the last read
 */
static char	*read_file(int fd, char *file)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	i = 1;
	while (!ft_strchr(file, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (0);
		}
		buff[i] = 0;
		file = ft_strjoin_gnl(file, buff);
	}
	free(buff);
	return (file);
}

/**
 * Submodule of get_next_line. Takes the output from the read_file
 * function and returns a new string containing file until the next new line
 * or NULL-terminator
 */
static char	*get_line(char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (!file || !file[i])
		return (0);
	line = (char *)malloc(find_char(file, 0) + 1);
	if (!line)
		return (0);
	while (file[i] != '\n' && file[i])
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

/**
 * Submodule of get_next_line. Scans the file input string for a new line
 * and cuts away everything in front of it or, in case none is found, frees
 * it and returns NULL
 */
static char	*cut_file(char *file)
{
	char	*newfile;
	int		i;
	int		a;

	i = 0;
	a = 0;
	i = find_char(file, '\n');
	if (file[i] == '\0')
	{
		free(file);
		return (0);
	}
	newfile = malloc(find_char(file, 0) - i + 1);
	if (!newfile)
		return (NULL);
	i++;
	while (file[i])
		newfile[a++] = file[i++];
	newfile[a] = '\0';
	free(file);
	return (newfile);
}

/**
 * Reads one line from the given filedescriptor and returns it
 * as a string
 * @param fd [int] filedescriptor to read from
 * @return pointer to a string containing next line from input fd
 */
char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	file = read_file(fd, file);
	if (!file)
		return (0);
	line = get_line(file);
	file = cut_file(file);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*test;

// 	printf("BUFFER_SIZE: %i\n", BUFFER_SIZE);
// 	fd = open("gnlTester/files/big_line_no_nl", O_RDWR);
// 	while (1)
// 	{
// 		test = get_next_line(fd);
// 		printf("%s", test);
// 		if (!test)
// 			break ;
// 		free(test);
// 	}
// 	close(fd);
// 	return (0);
// }
