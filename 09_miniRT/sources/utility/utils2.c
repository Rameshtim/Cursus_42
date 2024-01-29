/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:49:24 by kzhan             #+#    #+#             */
/*   Updated: 2024/01/26 15:41:16 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vec	reflect(t_vec light, t_vec normal)
{
	return (vec_sub(light, scale_vec(normal, 2 * vec_dot(light, normal))));
}

int	in_shadow(t_objects *obj, t_ray *ray, t_rec rec, double light_len)
{
	rec.tmax = light_len;
	check_hit(obj, ray, &rec);
	if (rec.tmax < light_len - EPSILON)
		return (1);
	return (0);
}
