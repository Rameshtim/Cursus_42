/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:00:38 by kzhan             #+#    #+#             */
/*   Updated: 2024/01/25 20:18:00 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vec	min_vec(t_vec vec1, t_vec vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

double	vec_len(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec	norm_vec(t_vec vec)
{
	double	len;

	len = vec_len(vec);
	if (len == 0)
		exit (1);
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

t_vec	scale_vec(t_vec vec, double s)
{
	vec.x *= s;
	vec.y *= s;
	vec.z *= s;
	return (vec);
}

//new vector (crossproduct) is perpendicular to both vec1 and vec2
t_vec	cross_prod(t_vec vec1, t_vec vec2)
{
	t_vec	cp;

	cp.x = vec1.y * vec2.z - vec2.y * vec1.z;
	cp.y = vec1.z * vec2.x - vec1.x * vec2.z;
	cp.z = vec1.x * vec2.y - vec2.x * vec1.y;
	return (cp);
}
