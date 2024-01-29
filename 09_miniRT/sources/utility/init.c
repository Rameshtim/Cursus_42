/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:56:48 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 21:00:30 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_vec	cam_set_vup(t_vec dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (make_vec(0, dir.y, EPSILON));
	else
		return (make_vec(0, 1, 0));
}

void	camera_init(t_camera *cam)
{
	t_vec	forward;
	t_vec	right;
	t_vec	up;

	cam->focal_len = tanf((cam->fov * PI / 180.0) / 2.0f);
	cam->viewport_h = cam->focal_len * 2;
	cam->viewport_w = cam->viewport_h * ((double)WIDTH / (double)HEIGHT);
	cam->dir = norm_vec(cam->dir);
	forward = norm_vec(scale_vec(cam->dir, -1));
	right = norm_vec(cross_prod(cam_set_vup(cam->dir), forward));
	up = cross_prod(forward, right);
	cam->hori = scale_vec(right, cam->viewport_w);
	cam->verti = scale_vec(up, cam->viewport_h);
	cam->left = vec_sub(vec_sub(vec_sub(cam->orig, \
		vec_scaled_div(cam->hori, 2)), \
		vec_scaled_div(cam->verti, 2)), forward);
}
