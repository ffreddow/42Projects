/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:10:37 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/10 20:34:54 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_storage		*store;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (0);
	store = init_store(argc, argv);
	if (check_error(store))
	{
		free(store);
		return (1);
	}
	forks = init_mutex(store->num_philos);
	create_threads(store, forks);
	free(forks);
	free(store);
	return (0);
}
