#include "philo.h"

void	ft_init_struct(t_philo *data, int argc, char **argv)
{
	data->name = 0;
	data->nb_p = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->forks = malloc(sizeof(char) * data->nb_p);
	memset(data->forks, 1,data->nb_p);
}
