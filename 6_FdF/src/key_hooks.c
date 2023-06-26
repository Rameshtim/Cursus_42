/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:56:19 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/05 17:24:00 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_hook(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		change_color(fdf, BLACK);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		change_color(fdf, WHITE);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		change_color(fdf, RED);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
		change_color(fdf, BLUE);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_4))
		change_color(fdf, SILVER);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_5))
		change_color(fdf, GREEN);
}

void	hook(void *param)
{
	t_fdf		*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		translate(fdf, 'y', -50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		translate(fdf, 'y', 50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		translate(fdf, 'x', -50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		translate(fdf, 'x', 50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		zoom(fdf, 1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		zoom(fdf, -1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
		change_height(fdf, 1.1, 1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
		change_height(fdf, 1.1, 0);
	color_hook(fdf);
}

void	close_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		mlx_terminate(fdf->mlx);
		exit (EXIT_SUCCESS);
	}
}
