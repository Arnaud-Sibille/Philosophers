#include "philo.h"

void	ft_init_data(t_data *data, int argc, char **argv)
{
	data->nb_p = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->th = malloc(sizeof(pthread_t) * data->nb_p);
	pthread_mutex_init(&(data->print_lock), NULL);
	pthread_mutex_init(&(data->start_lock), NULL);
	data->eat_lock = malloc(sizeof(pthread_mutex_t) * data->nb_p);
}
