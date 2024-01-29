/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:15:23 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 17:46:42 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void	update_sphere_hit(t_sphere *sp, t_ray *ray, t_rec *rec, double s)
{
	rec->tmax = s;
	rec->t = s;
	rec->point = ray_at(ray, s);
	rec->albedo = sp->color;
	rec->n_vec = vec_scaled_div(vec_sub(rec->point, sp->cor), sp->diam / 2);
}

void	hit_sphere(t_sphere *sp, t_ray *ray, t_rec *rec)
{
	t_vec	origin_center;
	t_disc	discriminant;
	double	s;

	origin_center = vec_sub(ray->orig, sp->cor);
	discriminant.a = square_vec(ray->dir);
	discriminant.b = vec_dot(origin_center, ray->dir);
	discriminant.c = square_vec(origin_center) - sp->diam * sp->diam / 4;
	discriminant.disc = discriminant.b * discriminant.b - \
		discriminant.a * discriminant.c;
	if (discriminant.disc < 0)
		return ;
	s = (-discriminant.b - sqrt(discriminant.disc)) / discriminant.a;
	if (!(s >= rec->tmin && s < rec->tmax))
	{
		s = (-discriminant.b + sqrt(discriminant.disc)) / discriminant.a;
		if (!(s >= rec->tmin && s < rec->tmax))
			return ;
	}
	update_sphere_hit(sp, ray, rec, s);
}
