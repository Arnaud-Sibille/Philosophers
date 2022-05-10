/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:27:01 by asibille          #+#    #+#             */
/*   Updated: 2022/05/10 13:01:19 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

#define LONGMAX 9223372036854775807

static int	ft_check_undef(const char *s, size_t val, int count, int sign)
{
	if (count == 19 && sign == 1)
	{
		if (val > LONGMAX)
			return (-1);
		else if (*s >= '0' && *s <= '9')
			return (-1);
	}
	else if (count == 19 && sign == -1)
	{
		if (val - 1 > LONGMAX)
			return (0);
		else if (*s >= '0' && *s <= '9')
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	size_t			val;
	int				count;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		++s;
	if (*s == '+')
		++s;
	if (!(*s >= '0' && *s <= '9'))
		return (-1);
	val = 0;
	count = 0;
	while (*s >= '0' && *s <= '9' && ++count)
	{
		val = val * 10 + *s - '0';
		++s;
		if (ft_check_undef(s, val, count, 1) == -1)
			return (0);
		else if (ft_check_undef(s, val, count, 1) == 0)
			return (0);
	}
	return ((int) val);
}
