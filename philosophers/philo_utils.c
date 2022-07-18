/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:17:59 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/10 20:16:54 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Joins all threads back to the main thread
 * 
 * @param philos_threads [pthread_t *] Array containing all thread ids of the
 * 							philosopher threads
 * @param death_check [pthread_t *] Pointer to the thread id of the
 * 							observer thread
 * @param num [int] Number of existing philosophers
 */
void	join_threads(pthread_t *philos_threads, pthread_t death_check, \
							int num)
{
	int	i;

	pthread_join(death_check, NULL);
	i = -1;
	while (++i < num)
		pthread_join(philos_threads[i], NULL);
}

/**
 * @brief Locks the mutex and sets the fork value to one
 * 
 * @param fork_mtx [pthread_mutex_t *] Pointer to mutex object
 * @param fork [int *] Pointer to fork value
 * @return int 1 if successfull, 0 if not
 */
int	grab_fork(pthread_mutex_t *fork_mtx, int *fork)
{
	if (fork_mtx)
	{
		if (pthread_mutex_lock(fork_mtx))
			return (1);
		*fork = 1;
		return (0);
	}
	return (1);
}

/**
 * @brief Get the current system-time in ms
 * 
 * @return [long long] Current system time in ms
 */
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * @brief Unlocks fork mutex and sets fork value to 0
 * 
 * @param fork_mtx [pthread_mutex_t *] Pointer to mutex object
 * @param fork [int *] Pointer to Fork Value
 */
void	return_fork(pthread_mutex_t *fork_mtx, int *fork)
{
	*fork = 0;
	pthread_mutex_unlock(fork_mtx);
}
