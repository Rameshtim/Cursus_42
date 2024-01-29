/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:54 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 18:25:22 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static double	getfirst(char **field, double *sign)
{
	double	first;

	*sign = 1;
	first = 0;
	while (**field && **field != '.')
	{
		if (**field == '-')
			*sign = -1;
		else
			first = first * 10 + (**field - '0');
		*field = *field + 1;
	}
	return (first);
}

double	ft_atod(char *field)
{
	double	first;
	double	second;
	int		digits;
	double	divisor;
	double	sign;

	sign = 1;
	divisor = 1;
	second = 0;
	first = getfirst(&field, &sign);
	digits = 0;
	if (*field)
		field++;
	while (*field)
	{
		digits++;
		second = second * 10 + (*field - '0');
		field++;
	}
	while (digits--)
		divisor *= 10;
	return (sign * (first + second / divisor));
}

int	in_range(double value, double min, double max)
{
	if ((min == 0 || min <= value) && (max == 0 || value <= max))
		return (1);
	return (0);
}

char	*remove_whitespace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}
