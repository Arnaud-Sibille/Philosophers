/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:03:28 by asibille          #+#    #+#             */
/*   Updated: 2022/05/09 18:03:29 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(size_t time)
{
	struct timeval	t0;

	gettimeofday(&t0, NULL);
	while (ft_cur_time(t0) < time)
		usleep(50);
}
