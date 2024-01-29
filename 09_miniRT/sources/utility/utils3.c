/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:49:57 by kzhan             #+#    #+#             */
/*   Updated: 2024/01/25 22:51:42 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_color	vec_to_color(t_vec vec)
{
	t_color	color;

	color.r = vec.x;
	color.g = vec.y;
	color.b = vec.z;
	return (color);
}

t_vec	color_to_vec(t_color color)
{
	t_vec	vec;

	vec.x = color.r;
	vec.y = color.g;
	vec.z = color.b;
	return (vec);
}

t_color	point_light_get(t_scene *scene, t_light *light, t_objects *obj)
{
	t_point_light	phong;
	t_color			color_point;

	phong.light_dir = vec_sub(light->cor, scene->rec.point);
	phong.light_ray = make_ray(vec_add(scene->rec.point, \
		scale_vec(scene->rec.n_vec, EPSILON)), phong.light_dir);
	if (in_shadow(obj, &phong.light_ray, scene->rec, vec_len(phong.light_dir)))
		return (make_color(0, 0, 0));
	phong.light_dir = norm_vec(phong.light_dir);
	phong.diff_fac = fmax(vec_dot(scene->rec.n_vec, phong.light_dir), 0.0);
	phong.diff = vec_to_color(scale_vec(color_to_vec(light->color), \
		phong.diff_fac * light->l_ratio));
	phong.view_dir = norm_vec(scale_vec(scene->ray.dir, -1));
	phong.refl_dir = reflect(scale_vec(phong.light_dir, -1), \
		scene->rec.n_vec);
	phong.spec_exp = 60;
	phong.spec_fac = 0.5;
	phong.spec_amt = pow(fmax(vec_dot(phong.view_dir, \
		phong.refl_dir), 0.0), phong.spec_exp);
	phong.spec = vec_to_color(scale_vec(scale_vec(color_to_vec(light->color), \
		phong.spec_fac * light->l_ratio), phong.spec_amt));
	color_point = vec_to_color(vec_add(color_to_vec(phong.diff), \
		color_to_vec(phong.spec)));
	return (color_point);
}

int	lighting(t_scene *scene, t_objects *obj)
{
	t_color	light_color;
	t_color	min_color;
	t_color	temp_light;
	int		i;

	i = 0;
	if (scene->rec.tmax > 99999 - 1)
		return (get_color(make_color(0, 0, 0)));
	temp_light = make_color(0, 0, 0);
	light_color = make_color(0, 0, 0);
	while (i < scene->lights_count)
	{
		temp_light = point_light_get(scene, &scene->light[i], obj);
		light_color = vec_to_color(vec_add(color_to_vec(light_color), \
			color_to_vec(temp_light)));
		i++;
	}
	light_color = vec_to_color(vec_add(color_to_vec(light_color), \
		scale_vec(color_to_vec(scene->ambient.color), scene->ambient.l_ratio)));
	min_color = vec_to_color(min_vec(vec_mult(color_to_vec(light_color), \
		color_to_vec(scene->rec.albedo)), color_to_vec(make_color(1, 1, 1))));
	return (get_color(min_color));
}
