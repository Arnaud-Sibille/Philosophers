#include "philo.h"

static void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->data->eat_lock + ph->name);
	pthread_mutex_lock(ph->data->eat_lock + p_ind(ph->name, ph->data->nb_p));
	ft_print(&(ph->data->print_lock), ph->data->t0, ph->name, "is eating");
	ph->last_ate = ft_cur_time(ph->data->t0);
	++(ph->ate);
	ft_sleep(ph->data->t_eat);
	pthread_mutex_unlock(ph->data->eat_lock + p_ind(ph->name, ph->data->nb_p));
	pthread_mutex_unlock(ph->data->eat_lock + ph->name);
}

void	*a_philo(void *phi)
{
	t_philo	*ph;

	ph = (t_philo *) phi;
	pthread_mutex_lock(&(ph->data->start_lock));
	ph->last_ate = ft_cur_time(ph->data->t0);
	pthread_mutex_unlock(&(ph->data->start_lock));
	if (ph->name % 2 || ph->name == ph->data->nb_p)
		ft_sleep(ph->data->t_eat / 2);
	while (ph->ate != ph->data->nb_eat)
	{
		ft_eat(ph);
		ft_print(&(ph->data->print_lock), ph->data->t0, ph->name, "is sleeping");
		ft_sleep(ph->data->t_sleep);
		ft_print(&(ph->data->print_lock), ph->data->t0, ph->name, "is thinking");
	}
	return (NULL);
}
