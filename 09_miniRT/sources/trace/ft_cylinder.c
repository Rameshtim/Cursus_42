/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:34:56 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 18:59:50 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	hit_cylinder_circle(t_cy *cy, t_ray *ray, t_rec *rec, double dir)
{
	t_vec	face_center;
	t_vec	intersec_point;
	double	numerator;
	double	intersec_dist;

	if (fabs(vec_dot(ray->dir, cy->v_dir)) < EPSILON)
		return ;
	face_center = vec_add(cy->cor, scale_vec(cy->v_dir, cy->height * dir / 2));
	numerator = vec_dot(vec_sub(face_center, \
		ray->orig), scale_vec(cy->v_dir, dir));
	intersec_dist = numerator / vec_dot(ray->dir, \
		scale_vec(cy->v_dir, dir));
	if (intersec_dist < rec->tmin || intersec_dist >= rec->tmax)
		return ;
	intersec_point = vec_add(ray->orig, scale_vec(ray->dir, intersec_dist));
	if (vec_len(vec_sub(face_center, intersec_point)) > cy->diam / 2)
		return ;
	rec->t = intersec_dist;
	rec->point = intersec_point;
	rec->tmax = intersec_dist;
	rec->n_vec = scale_vec(cy->v_dir, dir);
	rec->albedo = cy->color;
}

static int	check_height(t_cy *cy, t_vec point)
{
	double	hit_height;

	hit_height = vec_dot(vec_sub(point, cy->cor), cy->v_dir);
	if (fabs(hit_height) > cy->height / 2)
		return (0);
	return (1);
}

static t_vec	get_cylinder_normal(t_cy *cy, t_vec point)
{
	t_vec	hit_height;
	t_vec	normal;

	hit_height = scale_vec(cy->v_dir, \
	vec_dot(vec_sub(point, cy->cor), cy->v_dir));
	normal = vec_scaled_div(vec_sub(point, \
	vec_add(cy->cor, hit_height)), cy->diam / 2);
	return (normal);
}

void	hit_cylinder_body(t_cy *cy, t_ray *ray, t_rec *rec)
{
	t_vec	point;
	t_disc	disc;
	double	solutions;

	point = vec_sub(ray->orig, cy->cor);
	disc.a = square_vec(cross_prod(ray->dir, cy->v_dir));
	disc.b = vec_dot(cross_prod(ray->dir, cy->v_dir), \
		cross_prod(point, cy->v_dir));
	disc.c = square_vec(cross_prod(point, cy->v_dir)) - \
		((cy->diam * cy->diam) / 4);
	disc.disc = disc.b * disc.b - disc.a * disc.c;
	if (disc.disc < 0)
		return ;
	solutions = (-disc.b - sqrt(disc.disc)) / disc.a;
	if (!(solutions >= rec->tmin && solutions < rec->tmax))
	{
		solutions = (-disc.b + sqrt(disc.disc)) / disc.a;
		if (!(solutions >= rec->tmin && solutions < rec->tmax))
			return ;
	}
	if (!check_height(cy, ray_at(ray, solutions)))
		return ;
	update_cylinder_hit(cy, ray, rec, solutions);
}

void	update_cylinder_hit(t_cy *cy, t_ray *ray, t_rec *rec, double s)
{
	rec->tmax = s;
	rec->t = s;
	rec->point = ray_at(ray, s);
	rec->albedo = cy->color;
	rec->n_vec = get_cylinder_normal(cy, rec->point);
}
