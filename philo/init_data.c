/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:03:17 by asibille          #+#    #+#             */
/*   Updated: 2022/05/09 21:49:40 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->end = 0;
	data->nb_p = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->th = malloc(sizeof(pthread_t) * data->nb_p);
	if (!data->th)
		return (0);
	data->eat_lock = malloc(sizeof(pthread_mutex_t) * data->nb_p);
	if (!data->eat_lock)
	{
		free(data->th);
		return (0);
	}
	pthread_mutex_init(&(data->print_lock), NULL);
	pthread_mutex_init(&(data->start_lock), NULL);
	return (1);
}
