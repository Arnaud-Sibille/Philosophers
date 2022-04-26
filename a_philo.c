#include "philo.h"

void	*a_philo(void *phi)
{
	t_philo	*ph;

	ph = (t_philo *) phi;
	write(1, "yo\n", 3);
	pthread_mutex_lock(&(ph->data->start_lock));
	pthread_mutex_unlock(&(ph->data->start_lock));
	while (ph->ate != ph->data->nb_eat)
	{
		pthread_mutex_lock(ph->data->eat_lock + ph->name);
		pthread_mutex_lock(ph->data->eat_lock + p_ind(ph->name, ph->data->nb_p));
		ft_print(&(ph->data->print_lock), ph->data->t0, ph->name, "is eating");
		usleep(ph->data->t_eat * 1000);
		pthread_mutex_unlock(ph->data->eat_lock + p_ind(ph->name, ph->data->nb_p));
		pthread_mutex_unlock(ph->data->eat_lock + ph->name);
		++(ph->ate);
		ft_print(&(ph->data->print_lock), ph->data->t0, ph->name, "is sleeping");
		usleep(ph->data->t_sleep * 1000);
		ft_print(&(ph->data->print_lock), ph->data->t0, ph->name, "is thinking");
	}
	return (NULL);
}
