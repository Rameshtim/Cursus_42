/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:14:40 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 20:05:25 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	return (1);
}

void	err_msg(char *err_msg, char **splitted)
{
	int	i;

	i = 0;
	if (splitted != NULL)
		free_split(splitted);
	else
	{
		while (err_msg[i])
		{
			write(1, &err_msg[i], 1);
			i++;
		}
	}
	exit(1);
}
