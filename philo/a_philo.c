#include "philo.h"

static int	ft_can_eat(int name, char *forks, int nb_p)
{
	int	left;
	int	right;
	int	bit;

	bit = 0;
	left = name - 2;
	right = name - 1;
	if (name == 1)
		left = nb_p - 1;
	if (forks[right] == 1)
		bit = 1;
	if (forks[left] == 1)
		bit |= 2;
	return(bit);
}

void	*a_philo(void *data)
{
	t_philo	*dat;

	dat = (t_philo *) data;
	usleep(dat->name * 1000000);
	printf("----%zd---- %d\n", ft_cur_time(dat->t0), ft_can_eat(dat->name, dat->forks, dat->nb_p));
	ft_print_struct(data);
	return (NULL);
}