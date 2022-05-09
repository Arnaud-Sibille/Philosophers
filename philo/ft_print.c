#include "philo.h"

void	ft_print(pthread_mutex_t *print_lock, struct timeval t0, int philo, char *s)
{
	size_t	time = ft_cur_time(t0);
	pthread_mutex_lock(print_lock);
	printf("%zu %d %s\n", time, philo + 1, s);
	pthread_mutex_unlock(print_lock);
}