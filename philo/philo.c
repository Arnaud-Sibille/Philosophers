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
		ft_end(&data, philo);
		//ft_proper_exit(&data, philo); destroy mutexes and mallocs
	}
	return (0);
}
