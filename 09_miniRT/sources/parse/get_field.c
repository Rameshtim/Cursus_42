/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:05:34 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 14:21:31 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	fields_count(char **fields)
{
	int	len;

	len = 0;
	while (fields[len])
		len++;
	return (len);
}

int	valid_check_field(char *field, double min, double max, int is_in)
{
	char	**checker;
	int		i;

	i = 0;
	field = remove_whitespace(field);
	checker = ft_split(field, ',');
	if (!checker)
		return (0);
	if (fields_count(checker) != 3)
	{
		free_split(checker);
		printf("Error\nMust be 3 number field");
		return (0);
	}
	while (checker[i])
	{
		if (isnan(get_num(checker[i], min, max, is_in)) && free_split(checker))
			return (0);
		i++;
	}
	free_split(checker);
	return (1);
}

double	ret_num(double *dotcount, char *field, double range[3], int is_int)
{
	double	res;

	res = ft_atod(field);
	if (is_int)
	{
		if (*dotcount)
		{
			printf("Error\nNumber needs to be and Int.\n");
			return (NAN);
		}
	}
	else
	{
		if (1 < *dotcount)
		{
			printf("Error\nNumber can only contain one Decimal point.\n");
			return (NAN);
		}
	}
	if (!in_range(res, range[0], range[1]))
	{
		printf("Error\nNumber not in Range\n");
		return (NAN);
	}
	return (res);
}

double	get_num(char *field, double min, double max, int is_int)
{
	int		i;
	double	range[3];

	range[0] = min;
	range[1] = max;
	range[2] = 0;
	i = -1;
	while (field[++i])
	{
		if ((!ft_isdigit(field[i]) && field[i] != '.' && field[i] != '-'))
			return (printf("Error\nWrong Specifier\n"), (NAN));
		if (field[i] == '.' && ++range[2])
		{
			if (range[2] == 2)
				return (NAN);
			if (i == 0 || i == ft_strlen(field) - 1)
				return (printf("Error\n Leading or trailing decimal\n"), (NAN));
		}
		if ((field[i] == '-' && i != 0) || \
			(field[i] == '-' && field[i + 1] == '.'))
			return (printf("Error\nMinus at wrong position."), (NAN));
	}
	return (ret_num(&range[2], field, range, is_int));
}
