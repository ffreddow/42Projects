/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:25:53 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/10 20:34:25 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Destroys all mutexes
 * 
 * @param philos [t_philo *] Array containing all philo objects
 */
void	clean_mtx(t_philo *philos)
{
	int			i;

	i = -1;
	while (++i < philos[0].store->num_philos)
	{
		pthread_mutex_destroy(philos[i].left_fork_mtx);
		pthread_mutex_destroy(&philos[i].philo_mtx);
	}
	pthread_mutex_destroy(&philos[0].store->death_mtx);
}

/**
 * @brief Function used by the observer thread to check for dead philosophers
 * 
 * @param philo [t_philo *] pointer to a philosopher object
 * @return [int] 1 if philosopher died, 0 if alive
 */
static int	check_death(t_philo *philo)
{
	if (get_time() - philo->last_meal > \
			philo->store->time_to_die)
	{
		pthread_mutex_lock(&philo->store->death_mtx);
		philo->store->is_dead = 1;
		pthread_mutex_unlock(&philo->store->death_mtx);
		printf("%lld: %i died.\n", get_time() - philo->store->start_time, \
				philo->id);
		return (1);
	}
	return (0);
}

/**
 * @brief Function used by all philosophers to check if someone died
 * 
 * @param store [t_store *] Pointer to storage object
 * @return [int] 1 if someone died, 0 if not
 */
int	death_checker(t_storage *store)
{
	pthread_mutex_lock(&store->death_mtx);
	if (store->is_dead)
	{
		pthread_mutex_unlock(&store->death_mtx);
		return (1);
	}
	pthread_mutex_unlock(&store->death_mtx);
	return (0);
}

/**
 * @brief Cycles through every existing philosopher and checkes its state
 * 
 * @param philos_ptr [t_philo *] Array containing all philosopher objects
 * @return [void *] not used
 */
void	*observer(void *philos_ptr)
{
	int			i;
	t_philo		*philos;

	philos = (t_philo *)philos_ptr;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philos[i].philo_mtx);
		if ((philos[i].last_meal && check_death(&(philos[i]))) || \
			(philos[i].store->num_to_eat <= philos[i].meals_eaten && \
				philos[i].store->num_to_eat != -2))
			break ;
		pthread_mutex_unlock(&philos[i].philo_mtx);
		i++;
		if (i >= philos[0].store->num_philos)
			i = 0;
	}
	pthread_mutex_unlock(&philos[i].philo_mtx);
	return (0);
}

/**
 * @brief Allocates memory, zeroes it and returns a pointer to it
 * 
 * @param num [int] numberof elements to allocate
 * @param size [int] size of each element in bytes
 * @return [void *] pointer to allocated memory
 */
void	*ft_calloc(int num, int size)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(num * size);
	i = -1;
	while (++i < num * size)
		ret[i] = 0;
	return ((void *)ret);
}
