/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:14:26 by kzhan             #+#    #+#             */
/*   Updated: 2024/01/26 14:09:31 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	valid_ambient(char *line)
{
	char	**fields;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	line = remove_whitespace(line);
	fields = ft_split(line, ' ');
	if (!fields)
		return (0);
	if (fields_count(fields) != 3)
	{
		free_split(fields);
		printf("Error\nAmbient Light, wrong no. of fields");
		return (0);
	}
	if (isnan(get_num(fields[1], 0.0L, 1.0L, 0)) && free_split(fields))
		return (0);
	if (!valid_check_field(fields[2], 0.0L, 255.0L, 1) && free_split(fields))
		return (0);
	free_split(fields);
	return (1);
}

int	valid_camera(char *line)
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
		printf("Error\nCamera: Wrong no. of fields");
		return (0);
	}
	if (!valid_check_field(fields[1], 0.0L, 0.0L, 0) || \
		!valid_check_field(fields[2], -1.0L, 1.0L, 0))
	{
		free_split(fields);
		return (0);
	}
	if (isnan(get_num(fields[3], 0.0L, 180.0L, 1)) && free_split(fields))
		return (0);
	free_split(fields);
	return (1);
}

int	valid_light(char *line)
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
		printf("Error\nLight: Wrong no. of fields");
		return (0);
	}
	if (!valid_check_field(fields[1], 0.0L, 0.0L, 0) || \
		isnan(get_num(fields[2], 0.0L, 1.0L, 0)) || \
		!valid_check_field(fields[3], 0.0L, 255.0L, 1))
	{
		free_split(fields);
		return (0);
	}
	free_split (fields);
	return (1);
}
