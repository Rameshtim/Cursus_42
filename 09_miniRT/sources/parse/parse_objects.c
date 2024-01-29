/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:18:25 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 16:01:00 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	parse_sphere(char **splitted, t_objects *objects)
{
	t_sphere	*sphere;

	sphere = realloc_sp(objects, objects->sp);
	objects->sp++;
	put_coord(splitted[1], &sphere->cor);
	sphere->diam = ft_atod(splitted[2]);
	put_color(splitted[3], &sphere->color);
}

void	parse_plane(char **splitted, t_objects *objects)
{
	t_plane	*plane;

	plane = realloc_pl(objects, objects->pl);
	objects->pl++;
	put_coord(splitted[1], &plane->cor);
	put_normal_vec(splitted[2], &plane->v_dir);
	put_color(splitted[3], &plane->color);
}

void	parse_cylinder(char **splitted, t_objects *objects)
{
	t_cy	*cylinder;

	cylinder = realloc_cl(objects, objects->cy);
	objects->cy++;
	put_coord(splitted[1], &cylinder->cor);
	put_normal_vec(splitted[2], &cylinder->v_dir);
	cylinder->diam = ft_atod(splitted[3]);
	cylinder->height = ft_atod(splitted[4]);
	put_color(splitted[5], &cylinder->color);
}
