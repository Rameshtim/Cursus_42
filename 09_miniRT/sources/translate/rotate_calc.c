/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:36:08 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 20:04:29 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vec	rotate_y(t_vec vec, double angle)
{
	double	cos_a;
	double	sin_a;

	angle = angle * PI / 180.0;
	cos_a = cos(angle);
	sin_a = sin(angle);
	return (make_vec(vec.x * cos_a - vec.z * sin_a, \
		vec.y, vec.x * sin_a + vec.z * cos_a));
}

t_vec	rotate_x(t_vec vec, double angle)
{
	double	cos_a;
	double	sin_a;

	angle = angle * PI / 180.0;
	cos_a = cos(angle);
	sin_a = sin(angle);
	return (make_vec(vec.x, vec.y * cos_a - vec.z * sin_a, \
		vec.y * sin_a + vec.z * cos_a));
}

t_vec	rotate_z(t_vec vec, double angle)
{
	double	cos_a;
	double	sin_a;

	angle = angle * PI / 180.0;
	cos_a = cos(angle);
	sin_a = sin(angle);
	return (make_vec(vec.x * cos_a - vec.y * sin_a, \
		vec.x * sin_a + vec.y * cos_a, vec.z));
}
