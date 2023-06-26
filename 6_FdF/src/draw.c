/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 05:06:32 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/05 17:26:30 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawline(mlx_image_t *img, t_coord *c0, t_coord *c1, uint32_t rgb)
{
	t_linehelper	lh;

	lh_init(&lh, c0, c1);
	while (true)
	{
		if (lh.x >= 0 && lh.y >= 0 && lh.x < WIDTH && lh.y < HEIGHT)
			mlx_put_pixel(img, lh.x, lh.y, rgb);
		if ((lh.x == c1->x) && lh.y == c1->y)
			break ;
		lh.err2 = 2 * lh.err;
		if (lh.err2 >= lh.dy)
		{
			lh.err += lh.dy;
			lh.x += lh.sx;
		}
		if (lh.err2 <= lh.dx)
		{
			lh.err += lh.dx;
			lh.y += lh.sy;
		}
	}
}

static void	draw_reset(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(fdf->img, x, y, fdf->rgb);
			y++;
		}
		x++;
	}
}

static void	set_coords(t_fdf *fdf, t_point *pt, int x, int y)
{
	t_coord	c0;
	t_coord	c1;
	int		tmp_y;

	c0.x = round(fdf->map->x_start + x * fdf->map->spacing - y \
			* fdf->map->spacing);
	c0.y = round((fdf->map->y_start + y * fdf->map->spacing + x \
			* fdf->map->spacing) - pt->height);
	c1.x = c0.x + fdf->map->spacing;
	c1.y = round (c0.y + fdf->map->spacing + pt->height);
	tmp_y = c1.y;
	if (x < fdf->map->cols - 1 && pt->next)
	{
		c1.y = round(c1.y - pt->next->height);
		drawline(fdf->img, &c0, &c1, pt->color);
	}
	if (y < fdf->map->rows - 1)
	{
		c1.x = c1.x - 2 * fdf->map->spacing;
		c1.y = round(tmp_y - next_row_pt(pt, fdf->map->cols)->height);
		drawline(fdf->img, &c0, &c1, pt->color);
	}
}

void	draw(t_fdf *fdf, t_map *map)
{
	int		x;
	int		y;
	t_point	*pt;

	draw_reset(fdf);
	y = 0;
	pt = map->point;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			set_coords(fdf, pt, x, y);
			if (pt->next)
				pt = pt->next;
			x++;
		}
		y++;
	}
}
