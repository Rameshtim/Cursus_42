/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:09:38 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/21 15:41:17 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_new(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error(ERR_MAP_INIT);
	map->point = NULL;
	map->cols = 0;
	map->rows = 0;
	map->spacing = 3;
	map->x_start = 0;
	map->y_start = 0;
	map->highest = -2147483648;
	map->lowest = (float)2147483647;
	return (map);
}

void	translate(t_fdf *fdf, char xy, int amount)
{
	if (xy == 'x')
	{
		fdf->map->x_start += amount;
		draw (fdf, fdf->map);
	}
	if (xy == 'y')
	{
		fdf->map->y_start += amount;
		draw(fdf, fdf->map);
	}
}

void	zoom(t_fdf *fdf, int amount)
{
	if (fdf->map->spacing >= 2 && fdf->map->spacing <= 75)
	{
		if (fdf->map->spacing == 2)
			fdf->map->spacing += 1;
		if (fdf->map->spacing == 75)
			fdf->map->spacing -= 1;
		fdf->map->spacing += amount;
		draw(fdf, fdf->map);
	}
}

void	change_height(t_fdf *fdf, float factor, int up)
{
	t_point	*pt;

	pt = fdf->map->point;
	while (pt)
	{
		if (up == 1)
			pt->height = pt->height * factor;
		else
			pt->height = pt->height / factor;
		pt = pt->next;
	}
	draw (fdf, fdf->map);
}

void	change_color(t_fdf *fdf, uint32_t rgb)
{
	fdf->rgb = rgb;
	draw(fdf, fdf->map);
}
