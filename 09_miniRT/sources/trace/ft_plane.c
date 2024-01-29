/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:20:52 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 15:44:46 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	hit_plane(t_plane *pl, t_ray *ray, t_rec *rec)
{
	double	numerator;
	double	denominator;
	double	solutions;

	denominator = vec_dot(ray->dir, pl->v_dir);
	if (fabs(denominator) < EPSILON)
		return ;
	numerator = vec_dot(vec_sub(pl->cor, ray->orig), pl->v_dir);
	solutions = numerator / denominator;
	if (solutions < rec->tmin || solutions >= rec->tmax)
		return ;
	rec->tmax = solutions;
	rec->t = solutions;
	rec->point = ray_at(ray, solutions);
	rec->n_vec = pl->v_dir;
	rec->albedo = pl->color;
}
