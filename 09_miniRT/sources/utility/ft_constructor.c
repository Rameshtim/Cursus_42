/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:11:10 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 21:00:07 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vec	make_vec(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_color	make_color(double x, double y, double z)
{
	t_color	color;

	color.r = x;
	color.g = y;
	color.b = z;
	return (color);
}

t_ray	make_ray(t_vec point, t_vec vec)
{
	t_ray	ray;

	ray.orig = point;
	ray.dir = norm_vec(vec);
	return (ray);
}

//function to create rays that can be traced into the scene to 
//determine what the camera "sees" at each pixel position.
t_ray	make_view(t_camera *cam, double x, double y)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = norm_vec(vec_sub(vec_add(vec_add(cam->left, \
		scale_vec(cam->hori, x)), scale_vec(cam->verti, y)), \
		cam->orig));
	return (ray);
}
