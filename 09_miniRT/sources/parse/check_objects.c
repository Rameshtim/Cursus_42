/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:49:58 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 22:14:45 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	valid_sphere(char *line)
{
	char	**fields;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	line = remove_whitespace(line);
	fields = ft_split(line, ' ');
	if (!fields)
		return (0);
	if (fields_count(fields) != 4)
	{
		free_split(fields);
		printf("Error\nSphere: Wrong no. of fields");
		return (0);
	}
	if (!valid_check_field(fields[1], 0.0L, 0.0L, 0) || \
		(isnan(get_num(fields[2], 0.0L, 0.0L, 0))) \
		|| (!valid_check_field(fields[3], 0.0L, 255.0L, 1)))
	{
		free_split(fields);
		return (0);
	}
	free_split (fields);
	return (1);
}

int	valid_plane(char *line)
{
	char	**fields;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	line = remove_whitespace(line);
	fields = ft_split(line, ' ');
	if (!fields)
		return (0);
	if (fields_count(fields) != 4)
	{
		free_split(fields);
		printf("Error\nPlane: Wrong no. of fields");
		return (0);
	}
	if (!valid_check_field(fields[1], 0.0L, 0.0L, 0) \
	|| !valid_check_field(fields[2], -1.0L, 1.0L, 0) \
		|| !valid_check_field(fields[3], 0.0L, 255.0L, 1))
	{
		free_split(fields);
		return (0);
	}
	free_split (fields);
	return (1);
}

int	valid_cylinder(char *line)
{
	char	**fields;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	line = remove_whitespace(line);
	fields = ft_split(line, ' ');
	if (!fields)
		return (0);
	if (fields_count(fields) != 6)
	{
		free_split(fields);
		printf("Error\nCylinder: Wrong no. of fields");
		return (0);
	}
	if (!valid_check_field(fields[1], 0.0L, 0.0L, 0) \
		|| !valid_check_field(fields[2], -1.0L, 1.0L, 0) \
		|| isnan(get_num(fields[3], 0.0L, 0.0L, 0)) \
		|| isnan(get_num(fields[4], 0.0L, 0.0L, 0)) \
		|| !valid_check_field(fields[5], 0.0L, 255.0L, 1))
	{
		free_split(fields);
		return (0);
	}
	free_split(fields);
	return (1);
}
