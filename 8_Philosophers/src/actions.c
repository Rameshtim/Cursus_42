/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:16:34 by rtimsina          #+#    #+#             */
/*   Updated: 2023/10/01 14:14:18 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think(t_philo *philo)
{
	print_msg("is thinking", philo, philo->id);
}

void	philo_sleep(t_philo *philo)
{
	print_msg ("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	lone_philo(t_philo *philo)
{
	ft_usleep(philo->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_msg("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_msg("has taken a fork", philo, philo->id);
	}
	if (philo->num_of_philos == 1)
		return (lone_philo(philo));
	philo->eating = 1;
	print_msg("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	if (philo->id % 2 == 0)
		pthread_mutex_unlock(philo->l_fork);
	else
		pthread_mutex_unlock(philo->r_fork);
}
