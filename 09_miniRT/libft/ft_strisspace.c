/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:39:20 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/30 12:39:20 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisspace(char *str)
{
	int	check;

	if (!str || !(*str))
		return (0);
	check = 1;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			check = 0;
			break ;
		}
		str++;
	}
	return (check);
}
