#include "philo.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	if (argc == 5 || argc == 6)
	{
		ft_init_data(&data, argc, argv);
		philo = malloc(sizeof(t_philo) * data.nb_p);
		pthread_mutex_init(&(data.print_lock), NULL);
		pthread_mutex_init(&(data.start_lock), NULL);
		i = 0;
		pthread_mutex_lock(&(data.start_lock));
		while (i < data.nb_p)
		{
			pthread_mutex_init(data.eat_lock + i, NULL);
			(philo + i)->name = i;
			(philo + i)->ate = 0;
			(philo + i)->data = &data;
			pthread_create(data.th + i, NULL, a_philo, philo + i);
			++i;
		}
		gettimeofday(&(data.t0), NULL);
		pthread_mutex_unlock(&(data.start_lock));
		i = -1;
		while (++i < data.nb_p)
			pthread_join(data.th[i], NULL);
		pthread_mutex_destroy(&(data.print_lock));
		pthread_mutex_destroy(&(data.start_lock));
	}
	return (0);
}
