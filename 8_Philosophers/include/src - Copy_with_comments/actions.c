/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:16:34 by rtimsina          #+#    #+#             */
/*   Updated: 2023/11/09 14:57:18 by rtimsina         ###   ########.fr       */
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
	pthread_mutex_lock(philo->r_fork);
	ft_usleep(philo->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}

int	philo_acquire_forks(t_philo *philo)
{
	if (philo->r_fork < philo->l_fork)//check if neighbour fork is available
	{
		pthread_mutex_lock(philo->r_fork);//take their fork
		//ft_usleep(philo->time_to_eat / 2);
		if (philo->l_fork)//if own fork is avilable then take that as well
		{
			pthread_mutex_lock(philo->l_fork);
			print_msg("has taken a fork", philo, philo->id);
			print_msg("has taken a fork", philo, philo->id);
		}
		else//otherwise leave the fork that was taken
		{
			pthread_mutex_unlock(philo->r_fork);
			return (0);
		}
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		if (philo->r_fork)
		{
		//ft_usleep(philo->time_to_eat / 2);
			pthread_mutex_lock(philo->r_fork);
			print_msg("has taken a fork", philo, philo->id);
			print_msg("has taken a fork", philo, philo->id);
		}
		else
		{
			pthread_mutex_unlock(philo->l_fork);
			return (0);
		}
	}
	return (1);
	//ft_usleep(50);
}
void	philo_eat(t_philo *philo)
{
	if (philo->num_of_philos == 1)//only 1 philo should not eat and die
		return (lone_philo(philo));
	if (!philo->r_fork && !philo->l_fork)//if both forks are not available 
	{//sleep for time to eat * 2 / 10
		ft_usleep(philo->time_to_eat * 2);//just make for a short period of time to sleep
		return;
	}
	if (philo_acquire_forks(philo) == 0)//if philo was not able to acquire both forks
	{//then sleep for time to eat * 2 / 10
		ft_usleep(philo->time_to_eat * 2);
		return;		
	}
	philo->eating = 1;//if both forks are acquired start eating
	print_msg("is eating", philo, philo->id);//print is eating with philo id
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
