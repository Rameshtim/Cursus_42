/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:22:34 by rtimsina          #+#    #+#             */
/*   Updated: 2023/10/01 14:00:34 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (nptr[i])
	{
		if (i > 9 || (i == 9 && (nptr[i] - '0') >= 8))//checks int max
			return (0);
		else if (nptr[i] >= '0' && nptr[i] <= '9')//use atoi if and only if its integers and positive and in range
		{
			res = res * 10 + nptr[i] - '0';
			i++;
		}
		else
			return (0);
	}
	return (res);
}

int	check_valid_input(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 0) // if atoi returns 0 invalid
			return (0);
		else if (ft_atoi(str[1] > 200))
		{
			printf("No. of Philo must be less than 200\n");
			return (0);
		}
		else if (ft_atoi(str[2]) < 60 || ft_atoi(str[3]) < 60 || ft_atoi(str[4]) < 60)
		{
			printf("Time must be greater than 60 miliseconds\n");
			return (0);
		}
		i++;
	}
	return (1);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("gettimeofday() Failure\n");
		return (1);
	}
	return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
}

int	ft_usleep(time_t time)
{
	time_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	print_msg(char *str, t_philo *philo, int id)
{
	time_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->start_time;
	if (!dead_flag_check(philo))
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
