#include "philo.h"

size_t	ft_cur_time(struct timeval t0)
{
	size_t			time;
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	time = ((size_t) t1.tv_sec * 1000 + ((size_t) t1.tv_usec / 1000)) - ((size_t) t0.tv_sec * 1000 + ((size_t) t0.tv_usec / 1000));
	return (time);
}
