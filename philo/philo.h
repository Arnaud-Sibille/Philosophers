#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philo
{
	int				name;
	struct timeval	t0;
	char			*forks;
	size_t			nb_p;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;			
	int				nb_eat;
}				t_philo;

//a_philo
void	*a_philo(void *data);

//init_struct
void	ft_init_struct(t_philo *data, int argc, char **argv);

//cur_time
size_t	ft_cur_time(struct timeval t0);

//print.c
void ft_print_struct(t_philo *data);

//utils
int	ft_atoi(const char *s);

#endif