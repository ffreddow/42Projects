/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:04:38 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/11 11:38:05 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Starts each even philosopher with thinking
 * 
 * @param philo [t_philo *] Pointer to philosopher object
 */
static void	start_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->philo_mtx);
	if (philo->id % 2 == 0)
	{
		printf("%lld: %i is thinking.\n", get_time() - philo->store->start_time, \
				philo->id);
		usleep(philo->store->time_to_eat * 1000);
	}
}

/**
 * @brief Eating function of each philosopher. It locks the fork mutexes and
 * 			checks if someone died
 * 
 * @param philo [t_philo *] pointer to philo object
 * @return [int] 1 if someone died, 0 if not
 */
static int	eat(t_philo *philo)
{
	if (grab_fork(philo->left_fork_mtx, &philo->left_fork) || \
			death_checker(philo->store))
		return (1);
	printf("%lld: %i has taken a fork.\n", \
				get_time() - philo->store->start_time, philo->id);
	if (grab_fork(philo->right_fork_mtx, philo->right_fork) || \
			death_checker(philo->store))
		return (1);
	printf("%lld: %i has taken a fork.\n", \
				get_time() - philo->store->start_time, philo->id);
	if (death_checker(philo->store))
		return (1);
	pthread_mutex_lock(&philo->philo_mtx);
	printf("%lld: %i is eating.\n", get_time() - philo->store->start_time, \
			philo->id);
	philo->last_meal = get_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->philo_mtx);
	usleep(philo->store->time_to_eat * 1000);
	return_fork(philo->left_fork_mtx, &philo->left_fork);
	return_fork(philo->right_fork_mtx, philo->right_fork);
	return (0);
}

/**
  * @brief Thread function for each philosopher
  * 
  * @param philos [void *] Pointer to philosopher object
  * @return [void *] not used
  */
static void	*philosopher(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	start_philo(philo);
	while (1)
	{
		if (eat(philo))
			return (0);
		if (death_checker(philo->store))
			return (0);
		if (philo->store->num_to_eat != -2 && \
				philo->meals_eaten >= philo->store->num_to_eat)
			return (0);
		printf("%lld: %i is sleeping.\n", get_time() - philo->store->start_time, \
				philo->id);
		usleep(philo->store->time_to_sleep * 1000);
		if (death_checker(philo->store))
			return (0);
		printf("%lld: %i is thinking.\n", get_time() - philo->store->start_time, \
				philo->id);
	}
	return (0);
}

/**
 * @brief Set the philosopher objects
 * 
 * @param store [t_store *] Pointer to storage object
 * @param forks [pthread_mutex_t *] Array containing all fork mutexes
 * @return [t_philo *] Array containing all philosopher objects
 */
static t_philo	*set_philos(t_storage *store, pthread_mutex_t *forks)
{
	int			i;
	t_philo		*philos;

	i = -1;
	philos = (t_philo *)ft_calloc(store->num_philos, sizeof(t_philo));
	while (++i < store->num_philos - 1)
	{
		philos[i].id = i + 1;
		philos[i].left_fork_mtx = forks + i;
		philos[i].right_fork_mtx = forks + i + 1;
		philos[i].store = store;
		philos[i].right_fork = &philos[i + 1].left_fork;
		pthread_mutex_init(&philos[i].philo_mtx, NULL);
	}
	philos[i].id = i + 1;
	philos[i].left_fork_mtx = forks + i;
	philos[i].right_fork_mtx = forks;
	philos[i].store = store;
	philos[i].right_fork = &philos[0].left_fork;
	pthread_mutex_init(&philos[i].philo_mtx, NULL);
	return (philos);
}

/**
 * @brief Creates all philosophers and the observer threads and
 * 			joins them again.
 * 
 * @param store [t_storage *] Pointer to the storage object
 * @param forks [pthread_mutex_t *] Array containing all fork mutexes
 * @return [int] 0 if successfull, 1 if not
 */
int	create_threads(t_storage *store, pthread_mutex_t *forks)
{
	int			i;
	t_philo		*philos;
	pthread_t	death_check;
	pthread_t	*philos_threads;

	philos_threads = (pthread_t *)ft_calloc(store->num_philos, \
						sizeof(pthread_t));
	philos = set_philos(store, forks);
	i = -1;
	store->start_time = get_time();
	if (pthread_create(&death_check, NULL, observer, (void *)philos))
		return (1);
	while (++i < store->num_philos)
	{
		if (pthread_create(&(philos_threads[i]), NULL, (void *)philosopher, \
				(void *)&(philos[i])))
			return (1);
	}
	join_threads(philos_threads, death_check, store->num_philos);
	clean_mtx(philos);
	free(philos);
	free(philos_threads);
	return (0);
}
