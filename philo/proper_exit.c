/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proper_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:18:54 by asibille          #+#    #+#             */
/*   Updated: 2022/05/10 11:53:09 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_proper_exit(t_data *data, t_philo *ph)
{
	int	i;

	i = -1;
	if (data->nb_p == 1)
		pthread_mutex_unlock(ph->data->eat_lock);
	while (++i < data->nb_p)
		pthread_join(*(data->th + i), NULL);
	free(data->th);
	free(ph);
	pthread_mutex_destroy(&(data->start_lock));
	pthread_mutex_destroy(&(data->print_lock));
	i = 0;
	while (i < data->nb_p)
	{
		pthread_mutex_destroy(data->eat_lock + i);
		++i;
	}
	free(data->eat_lock);
}
