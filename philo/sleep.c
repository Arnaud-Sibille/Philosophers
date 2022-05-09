#include "philo.h"

void	ft_sleep(size_t time)
{
	struct timeval	t0;

	gettimeofday(&t0, NULL);
	while (ft_cur_time(t0) < time)
		usleep(50);
}
