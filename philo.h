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
}				t_data;

typedef struct s_philo
{
	int		name;
	int		ate;
	t_data	*data;
}				t_philo;

//init_data
void	ft_init_data(t_data *data, int argc, char **argv);

//cur_time
size_t	ft_cur_time(struct timeval t0);

//a_philo
void	*a_philo(void *phi);

//print
void	ft_print(pthread_mutex_t *print_lock, struct timeval t0, int philo, char *s);

//next_and_prev
int		p_ind(int name, int nb_p);

//utils
int		ft_atoi(const char *s);

#endif