/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:03:25 by asibille          #+#    #+#             */
/*   Updated: 2022/05/10 12:51:29 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_init(t_philo *ph, t_data *data, int i)
{
	pthread_mutex_init(data->eat_lock + i, NULL);
	(ph + i)->name = i;
	(ph + i)->ate = 0;
	(ph + i)->last_ate = 0;
	(ph + i)->data = data;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	if ((argc == 5 || argc == 6) && ft_atoi(argv[1]) >= 0)
	{
		philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (!philo)
			return (1);
		if (!ft_init_data(&data, argc, argv, philo))
			return (1);
		i = 0;
		pthread_mutex_lock(&(data.start_lock));
		while (i < data.nb_p)
		{
			ft_philo_init(philo, &data, i);
			pthread_create(data.th + i, NULL, a_philo, philo + i);
			++i;
		}
		gettimeofday(&(data.t0), NULL);
		pthread_mutex_unlock(&(data.start_lock));
		ft_end(&data, philo);
		ft_proper_exit(&data, philo);
	}
	return (0);
}
