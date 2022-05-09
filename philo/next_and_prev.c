#include "philo.h"

int	p_ind(int name, int nb_p)
{
	if (name == 0)
		return (nb_p - 1);
	else
		return (name - 1);
}

/*
int	n_ind(int name, int nb_p)
{
	if (name == nb_p - 1)
		return (0);
	else
		return (name + 1);
}
*/