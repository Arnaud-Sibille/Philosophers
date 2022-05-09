/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:03:13 by asibille          #+#    #+#             */
/*   Updated: 2022/05/09 21:45:39 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(pthread_mutex_t *pl, t_data *data, int philo, char *s)
{
	pthread_mutex_lock(pl);
	if (!(data->end))
		printf("%zu %d %s\n", ft_cur_time(data->t0), philo + 1, s);
	pthread_mutex_unlock(pl);
}
