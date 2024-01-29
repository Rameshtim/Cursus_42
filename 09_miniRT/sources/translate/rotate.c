/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:07:13 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 16:04:28 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	camera_rotate_keys(t_mrt *mrt)
{
	t_vec	*dir;

	dir = &mrt->scene.camera.dir;
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_UP))
		*dir = rotate_y(*dir, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_DOWN))
		*dir = rotate_y(*dir, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_LEFT))
		*dir = rotate_x(*dir, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_RIGHT))
		*dir = rotate_x(*dir, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_PAGE_UP))
		*dir = rotate_z(*dir, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_PAGE_DOWN))
		*dir = rotate_z(*dir, -15);
}

void	traverse_pl_rotate(t_objects *obj, int xyz, double change)
{
	int		i;
	t_vec	*dir;

	i = -1;
	while (++i < obj->pl)
	{
		dir = &obj->planes[i].v_dir;
		if (xyz == 0)
			*dir = rotate_x(*dir, change);
		if (xyz == 1)
			*dir = rotate_y(*dir, change);
		if (xyz == 2)
			*dir = rotate_z(*dir, change);
	}
}

void	traverse_cy_rotate(t_objects *obj, int xyz, double change)
{
	int		i;
	t_vec	*dir;

	i = -1;
	while (++i < obj->cy)
	{
		dir = &obj->cylinders[i].v_dir;
		if (xyz == 0)
			*dir = rotate_x(*dir, change);
		if (xyz == 1)
			*dir = rotate_y(*dir, change);
		if (xyz == 2)
			*dir = rotate_z(*dir, change);
	}
}
