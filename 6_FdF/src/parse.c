/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:06:59 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/21 15:48:39 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	get_color(t_fdf *fdf, char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
			return (ft_atoi_base(&str[i + 3], 16) * 256 + 255);
		i++;
	}
	return (fdf->line_rgb);
}

static void	fill_points(t_fdf *fdf, char **array, t_map *map)
{
	int		i;
	float	height;

	i = 0;
	map->cols = 0;
	while (array[i])
	{
		if (array[i][0] != '\n')
		{
			height = ft_atoi(array[i]);
			if (height > map->highest)
				map->highest = height;
			if (height < map->lowest)
				map->lowest = height;
			if (!map->point)
				map->point = pt_new(height, get_color(fdf, array[i]));
			else
				pt_add_back(map->point, pt_new(height, \
				get_color(fdf, array[i])));
			map->cols++;
		}
		i++;
	}
}

static void	get_points(t_fdf *fdf, int fd, t_map *map)
{
	char	*line;
	char	**array;

	line = get_next_line(fd);
	while (line)
	{
		array = ft_split(line, ' ');
		map->rows++;
		fill_points(fdf, array, map);
		free (line);
		free_array(array);
		line = get_next_line(fd);
	}
}

t_map	*parse(t_fdf *fdf, int fd)
{
	t_map	*map;
	float	x_spacing;
	float	y_spacing;

	map = map_new();
	get_points(fdf, fd, map);
	x_spacing = WIDTH / (float)(map->cols + map->rows);
	y_spacing = (HEIGHT - map->highest + map->lowest) \
				/ (float)(map->cols + map->rows + 2);
	if (x_spacing > y_spacing)
		map->spacing = floor(y_spacing);
	else
		map->spacing = floor(x_spacing);
	map->x_start = round(map->spacing * map->rows);
	map->y_start = round(map->spacing + map->highest);
	return (map);
}
