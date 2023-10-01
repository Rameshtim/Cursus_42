/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:24:57 by rtimsina          #+#    #+#             */
/*   Updated: 2023/10/01 14:10:51 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	time_t			last_meal;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*meal_check;
}					t_philo;
typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_check;
	t_philo			*philos;
}					t_data;

//philo.c
int		main(int argc, char *argv[]);

//threads.c
void	destroy_all(t_data *data, pthread_mutex_t *forks);
void	*philo_routine(void	*philos);
int		thread_create(t_data *data, pthread_mutex_t	*forks);

//actions.c
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);

//monitor.c
int		dead_flag_check(t_philo *philo);
int		philo_dead(t_philo *philo, time_t	time_to_die);
int		check_dead(t_philo *philos);
int		check_eaten(t_philo *philos);
void	*monitor(void *philo);

//utils.c
int		ft_atoi(const char *nptr);
int		check_valid_input(char **str);
time_t	get_time(void);
int		ft_usleep(time_t time);
void	print_msg(char *str, t_philo *philo, int id);

//init.c
void	init_data(t_data *data, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int nb_philo);
void	init_input(t_philo *philo, char **argv);
void	init_philos(t_philo *philos, t_data *data, \
		pthread_mutex_t *forks, char **argv);

#endif