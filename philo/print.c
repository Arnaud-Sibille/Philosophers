#include "philo.h"

void ft_print_struct(t_philo *data)
{
	int i;

	printf("name:%d  t0:%ldsec  nb_p:%zu  t_die:%zums  t_eat:%zums  t_sleep:%zums  nb_eat:%d\n", data->name, data->t0.tv_sec, data->nb_p, data->t_die, data->t_eat, data->t_sleep, data->nb_eat);
	i = 0;
	while (i < data->nb_p)
	{
		printf("f%d:%d ", i, data->forks[i]);
		++i;
	}
	printf("\n");
}
