#include "philo.h"

int main(int argc, char **argv)
{
	t_philo			*data;
	struct timeval	t0;
	int				i;
	pthread_t		*th;
	int				nb;

	if (argc == 5 || argc == 6)
	{
		nb = ft_atoi(argv[1]);
		data = malloc(sizeof(t_philo) * nb);
		th = malloc(sizeof(pthread_t) * nb);
		i = -1;
		while (++i < nb)
			ft_init_struct(data + i, argc, argv);
		gettimeofday(&t0, NULL);
		i = -1;
		while (++i < nb)
		{
			(data + i)->t0 = t0;
			(data + i)->name = i + 1;
			pthread_create(th + i, NULL, a_philo, data + i);
		}
		i = -1;
		while (++i < nb)
			pthread_join(th[i], NULL);
	}
}











/*
int	main(int argc, char **argv)
{
	struct timeval  t0;
	int             count;

	gettimeofday(&t0, NULL);
	count = ft_atoi(argv[1]);
	while (count > 0)
	{
		usleep(1000000);
		printf("%zu ms\n", ft_cur_time(t0));
		--count;
	}

	return (0);
}

int main() {
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicro seconds : %d",
		current_time.tv_sec, current_time.tv_usec);

	return 0;
}
*/
