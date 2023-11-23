/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:02:17 by rtimsina          #+#    #+#             */
/*   Updated: 2023/11/09 15:00:40 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_all(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->meal_check);
	pthread_mutex_destroy(&data->dead_lock);
	while (i < data->philos->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	*philo_routine(void	*philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (!dead_flag_check(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		ft_usleep(1);
	}
	return (NULL);
}

//create thread after some sleep
//should also die while sleeping
int	thread_create(t_data *data, pthread_mutex_t	*forks)
{
	pthread_t	checker;
	int			i;

	//here monitor in checker thread will always check in a loop if philo has eaten in time and not dead
	if (pthread_create(&checker, NULL, &monitor, data->philos) != 0)//create a thread for all philos with monitor function
		destroy_all(data, forks);// if not successful destory all locks and forks
	i = 0;
	while (i < data->philos->num_of_philos)
	{
		//philo_routine will let philosophers eat sleep or think in a loop as long as nobody is dead
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, \
			&data->philos[i]) != 0)//create a thread for everyphilo with philo_routine function
			destroy_all(data, forks);
		i++;
	}
	i = 0;
	//pthread_join is like a coordination point where one thread waits another thread to finish before moving forward
	if (pthread_join(checker, NULL) != 0)
		destroy_all(data, forks);
	while (i < data->philos->num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all (data, forks);
		i++;
	}
	return (0);
}
