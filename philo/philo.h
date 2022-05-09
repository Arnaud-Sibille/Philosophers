/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:14:52 by asibille          #+#    #+#             */
/*   Updated: 2022/05/09 21:45:00 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	int				nb_p;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	struct timeval	t0;
	pthread_t		*th;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	*eat_lock;
	int				end;
}				t_data;

typedef struct s_philo
{
	int		name;
	int		ate;
	int		last_ate;
	t_data	*data;
}				t_philo;

//init_data
int		ft_init_data(t_data *data, int argc, char **argv);

//cur_time
size_t	ft_cur_time(struct timeval t0);

//a_philo
void	*a_philo(void *phi);

//print
void	ft_print(pthread_mutex_t *pl, t_data *data, int philo, char *s);

//next_and_prev
int		p_ind(int name, int nb_p);

//sleep
void	ft_sleep(size_t time);

//end
int		ft_end(t_data *data, t_philo *ph);

//proper_exit
void	ft_proper_exit(t_data *data, t_philo *ph);

//utils
int		ft_atoi(const char *s);

#endif