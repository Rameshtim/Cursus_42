/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:02:34 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 15:57:54 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	get_color(t_color c)
{
	return (((int)(c.r * 255) << 24) + ((int)(c.g * 255) << 16) + \
		((int)(c.b * 255) << 8) + 255);
}

void	set_face_normal(t_ray *ray, t_rec *rec)
{
	if (vec_dot(ray->dir, rec->n_vec) > 0)
		rec->n_vec = scale_vec(rec->n_vec, -1);
}

t_vec	ray_at(t_ray *ray, double t)
{
	return (vec_add(ray->orig, scale_vec(ray->dir, t)));
}

void	check_hit(t_objects *obj, t_ray *ray, t_rec *rec)
{
	int	i;

	i = -1;
	while (++i < obj->sp)
		hit_sphere(&obj->spheres[i], ray, rec);
	i = -1;
	while (++i < obj->pl)
		hit_plane(&obj->planes[i], ray, rec);
	i = -1;
	while (++i < obj->cy)
	{
		hit_cylinder_circle(&obj->cylinders[i], ray, rec, -1);
		hit_cylinder_circle(&obj->cylinders[i], ray, rec, 1);
		hit_cylinder_body(&obj->cylinders[i], ray, rec);
	}
}

int	color_obj(t_scene *scene, t_objects *obj)
{
	int	color;

	check_hit(obj, &scene->ray, &scene->rec);
	set_face_normal(&scene->ray, &scene->rec);
	color = lighting(scene, obj);
	return (color);
}
