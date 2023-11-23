/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 09:00:48 by rtimsina          #+#    #+#             */
/*   Updated: 2023/10/01 13:59:25 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_input(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_data *data, \
		pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1; //we can say i = 1. to make first philo as 1 and not as 0
		philos[i].eating = 0; //nobody is eating in begining
		philos[i].meals_eaten = 0; //not eaten
		init_input(&philos[i], argv);//assigh no. of philo, time to eat and sleep or no. of meals
		philos[i].start_time = get_time();//get the begining time in miliseconds
		philos[i].last_meal = get_time();
		philos[i].write_lock = &data->write_lock;//assign philo write_lock to data write_lock
		philos[i].dead_lock = &data->dead_lock;//which is a thread mutex and was
		philos[i].meal_lock = &data->meal_lock;j//initialized by init_data function
		philos[i].meal_check = &data->meal_check;
		philos[i].dead = &data->dead_flag;
		philos[i].l_fork = &forks[i];//assign every philos left fork
		if (i == 0) // if first philo their right fork is last philo left fork
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else// otherwise their right fork is next philo on the rights left fork
			philos[i].r_fork = &forks[i - 1];
		i++;//working clockwise
	}
}

void	init_data(t_data *data, t_philo *philos)
{
	data->dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->meal_check, NULL);
}

void	init_forks(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = 0;
	//each philo must have one fork and only one fork
	//initialize 1 fork each for every philosophers.
	while (i < nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
