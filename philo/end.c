#include "philo.h"

void	ft_end(t_data *data, t_philo *ph)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (1)
	{
		if ((ph + i)->ate == data->nb_eat)
			++count;
		else
		{
			count = 0;
			if ((int) ft_cur_time(data->t0) - (ph + i)->last_ate > data->t_die)
			{
				pthread_mutex_lock(&(data->print_lock));
				printf("%zu %d %s\n", ft_cur_time(data->t0), (ph + i)->name + 1, "died");
				return ;
			}
		}
		if (count == data->nb_p)
		{
			pthread_mutex_lock(&(data->print_lock));
			return ;
		}
		i = p_ind(i, data->nb_p);
	}
}