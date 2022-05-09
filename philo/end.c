/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:03:10 by asibille          #+#    #+#             */
/*   Updated: 2022/05/09 21:41:42 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_exit(t_data *data, t_philo *ph, int i, int mode)
{
	if (mode == 1)
	{
		pthread_mutex_lock(&(data->print_lock));
		data->end = 1;
		printf("%zu %d %s\n", ft_cur_time(data->t0), (ph + i)->name + 1, "died");
		pthread_mutex_unlock(&(data->print_lock));
	}
	if (mode == 2)
	{
		pthread_mutex_lock(&(data->print_lock));
		data->end = 1;
		pthread_mutex_unlock(&(data->print_lock));
	}
	return (0);
}

int	ft_end(t_data *data, t_philo *ph)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (1)
	{
		if (data->nb_eat != -1 && (ph + i)->ate >= data->nb_eat)
			++count;
		else
		{
			count = 0;
			if ((int) ft_cur_time(data->t0) - (ph + i)->last_ate > data->t_die)
				return (ft_exit(data, ph, i, 1));
		}
		if (count == data->nb_p)
			return (ft_exit(data, ph, i, 2));
		i = p_ind(i, data->nb_p);
	}
}
