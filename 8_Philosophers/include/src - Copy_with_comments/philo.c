/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:55:15 by rtimsina          #+#    #+#             */
/*   Updated: 2023/10/01 13:56:43 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			philos[201];
	pthread_mutex_t	forks[201];

	if (argc < 5 || argc > 6)
	{
		printf("format error\n");
		return (1);
	}
	if (!check_valid_input(argv))
	{
		printf("Input must be valid positive integers!\n");
		return (2);
	}
	init_data(&data, philos);//initialize mutex locks
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &data, forks, argv);
	thread_create(&data, forks);
	destroy_all(&data, forks);
	return (0);
}
