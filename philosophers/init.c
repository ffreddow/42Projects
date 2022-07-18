/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:29:35 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/18 10:47:24 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Catches the case of one philosopher
 * 
 * @param store [t_storage *] Pointer to storage object
 */
static void	catch_one(t_storage *store)
{
	printf("0: 1 has taken a fork\n");
	usleep(store->time_to_sleep * 1000);
	printf("%i: 1 died\n", store->time_to_die);
}

/**
 * @brief Converts array to positive integer, has inbuild overflow
 * 			protection
 * 
 * @param str [char *] String to convert
 * @return Number converted from string, -1 if an error occured
 */
static int	ft_atoi(char *str)
{
	int		tmp;
	long	num;

	num = 0;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (-1);
		tmp = *str - '0';
		num *= 10;
		num += (long)tmp;
		str++;
	}
	if (num > __INT_MAX__)
		return (-1);
	return ((int)num);
}

/**
 * @brief Initialises storage struct
 * 
 * @param argc [int] Number of arguments passed to the program
 * @param argv [char **] Array of arguments passed to the program
 * @return [t_storage *] Pointer the storage struct
 */
t_storage	*init_store(int argc, char **argv)
{
	t_storage	*store;

	store = ft_calloc(1, sizeof(t_storage));
	if (!store)
		return (0);
	store->num_philos = ft_atoi(argv[1]);
	store->time_to_die = ft_atoi(argv[2]);
	store->time_to_eat = ft_atoi(argv[3]);
	store->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		store->num_to_eat = ft_atoi(argv[5]);
	else
		store->num_to_eat = -2;
	pthread_mutex_init(&store->death_mtx, NULL);
	return (store);
}

/**
 * @brief Initialises the mutexes
 * 
 * @param n [int] Number to initiate
 * @return [pthread_mutex_t *] Pointer to array of mutexes
 */
pthread_mutex_t	*init_mutex(int n)
{
	int					i;
	pthread_mutex_t		*mutex;

	i = -1;
	mutex = (pthread_mutex_t *)ft_calloc(n, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < n)
		pthread_mutex_init(&mutex[i], NULL);
	return (mutex);
}

/**
 * @brief Checks for errors in ft_atoi function
 * 
 * @param store [t_storage *] Pointer to storage struct
 * @return [int] 0 if no error occured 1 if an error occured
 */
int	check_error(t_storage *store)
{
	if (store->num_philos == -1)
		return (1);
	if (store->num_to_eat == -1)
		return (1);
	if (store->time_to_die == -1)
		return (1);
	if (store->time_to_eat == -1)
		return (1);
	if (store->time_to_sleep == -1)
		return (1);
	if (store->num_philos == 1)
	{
		catch_one(store);
		return (1);
	}
	return (0);
}
