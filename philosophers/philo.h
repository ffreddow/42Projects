/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrich <fhenrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:11:05 by fhenrich          #+#    #+#             */
/*   Updated: 2022/07/10 20:34:37 by fhenrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_storage
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	int				is_dead;
	long long		start_time;
	pthread_mutex_t	death_mtx;
}	t_storage;

typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					*right_fork;
	int					meals_eaten;
	long double			last_meal;
	t_storage			*store;
	pthread_mutex_t		philo_mtx;
	pthread_mutex_t		*left_fork_mtx;
	pthread_mutex_t		*right_fork_mtx;
}	t_philo;

int				check_error(t_storage *store);
int				death_checker(t_storage *store);
int				create_threads(t_storage *store, pthread_mutex_t *forks);
int				grab_fork(pthread_mutex_t *fork_mtx, int *fork);
void			clean_mtx(t_philo *philos);
void			*ft_calloc(int num, int size);
void			*observer(void *philos_ptr);
void			return_fork(pthread_mutex_t *fork_mtx, int *fork);
void			join_threads(pthread_t *philos_threads, pthread_t death_check, \
							int num);
long long		get_time(void);
t_storage		*init_store(int argc, char **argv);
pthread_mutex_t	*init_mutex(int n);

#endif