/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:03:06 by asibille          #+#    #+#             */
/*   Updated: 2022/05/09 18:06:08 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_cur_time(struct timeval t0)
{
	size_t			time;
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	time = ((size_t) t1.tv_sec * 1000 + ((size_t) t1.tv_usec / 1000))
		- ((size_t) t0.tv_sec * 1000 + ((size_t) t0.tv_usec / 1000));
	return (time);
}
