Philosophers is about multithreading. There are as many philosophers at a table as the user defines. Each philosopher brings one fork to th table. Each philosopher eats, sleeps and thinks repeadedly.
To eat every philosopher needs two forks to eat (weird I know), thus making both forks next to him unavailable. A philosopher dies if he does not eat anything
in a user defined time. They have no way of communication and dont know when another philosopher is about to die, but must avoid dieing.

-------------------------------------------

Usage: philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]

-------------------------------------------

It works by creating the threads and delaying each other thread by the time needed to eat.
Allowed functions: memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
