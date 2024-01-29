/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:45:44 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 21:01:08 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	camera_translate_keys(t_mrt *mrt)
{
	t_vec	*orig;

	orig = &mrt->scene.camera.orig;
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_E))
		*orig = vec_add(*orig, make_vec(0, 0.2, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_R))
		*orig = vec_add(*orig, make_vec(0, -0.2, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_T))
		*orig = vec_add(*orig, make_vec(0.2, 0, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_Y))
		*orig = vec_add(*orig, make_vec(-0.2, 0, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_U))
		*orig = vec_add(*orig, make_vec(0, 0, 0.2));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_I))
		*orig = vec_add(*orig, make_vec(0, 0, -0.2));
}

void	sphere_translate_keys(t_mrt *mrt)
{
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_O))
		traverse_sp_translate(&mrt->objects, 0, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_P))
		traverse_sp_translate(&mrt->objects, 0, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_LEFT_BRACKET))
		traverse_sp_translate(&mrt->objects, 1, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_RIGHT_BRACKET))
		traverse_sp_translate(&mrt->objects, 1, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_Q))
		traverse_sp_translate(&mrt->objects, 2, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_W))
		traverse_sp_translate(&mrt->objects, 2, -0.2);
}

void	light_translate_keys(t_mrt *mrt)
{
	t_vec	*orig;

	orig = &mrt->scene.light->cor;
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_1))
		*orig = vec_add(*orig, make_vec(0, 0.2, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_2))
		*orig = vec_add(*orig, make_vec(0, -0.2, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_3))
		*orig = vec_add(*orig, make_vec(0.2, 0, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_4))
		*orig = vec_add(*orig, make_vec(-0.2, 0, 0));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_5))
		*orig = vec_add(*orig, make_vec(0, 0, 0.2));
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_6))
		*orig = vec_add(*orig, make_vec(0, 0, -0.2));
}

void	plane_keys(t_mrt *mrt)
{
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_A))
		traverse_pl_rotate(&mrt->objects, 0, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_S))
		traverse_pl_rotate(&mrt->objects, 0, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_D))
		traverse_pl_rotate(&mrt->objects, 1, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_F))
		traverse_pl_rotate(&mrt->objects, 1, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_G))
		traverse_pl_rotate(&mrt->objects, 2, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_H))
		traverse_pl_rotate(&mrt->objects, 2, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_7))
		traverse_pl_translate(&mrt->objects, 0, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_8))
		traverse_pl_translate(&mrt->objects, 0, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_9))
		traverse_pl_translate(&mrt->objects, 1, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_0))
		traverse_pl_translate(&mrt->objects, 1, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_MINUS))
		traverse_pl_translate(&mrt->objects, 2, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_EQUAL))
		traverse_pl_translate(&mrt->objects, 2, -0.2);
}

void	cylinder_keys(t_mrt *mrt)
{
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_Z))
		traverse_cy_translate(&mrt->objects, 0, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_X))
		traverse_cy_translate(&mrt->objects, 0, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_C))
		traverse_cy_translate(&mrt->objects, 1, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_V))
		traverse_cy_translate(&mrt->objects, 1, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_B))
		traverse_cy_translate(&mrt->objects, 2, 0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_N))
		traverse_cy_translate(&mrt->objects, 2, -0.2);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_J))
		traverse_cy_rotate(&mrt->objects, 0, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_K))
		traverse_cy_rotate(&mrt->objects, 0, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_L))
		traverse_cy_rotate(&mrt->objects, 1, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_M))
		traverse_cy_rotate(&mrt->objects, 1, -15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_COMMA))
		traverse_cy_rotate(&mrt->objects, 2, 15);
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_PERIOD))
		traverse_cy_rotate(&mrt->objects, 2, -15);
}
