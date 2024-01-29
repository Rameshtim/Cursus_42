/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:39:46 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 19:00:51 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
// #include "../../MLX42/include/MLX42/MLX42_Int.h"

static void	mlx_draw_pixel(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	uint8_t	*pixelstart;

	pixelstart = &img->pixels[(y * img->width + x) * sizeof(int32_t)];
	mlx_draw_pixel(pixelstart, color);
}
