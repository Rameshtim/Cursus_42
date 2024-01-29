/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:31:31 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 21:01:41 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	traverse_sp_translate(t_objects *obj, int xyz, double change)
{
	int		i;
	t_vec	*dir;

	i = -1;
	while (++i < obj->sp)
	{
		dir = &obj->spheres[i].cor;
		if (xyz == 0)
			*dir = vec_add(*dir, make_vec(change, 0, 0));
		if (xyz == 1)
			*dir = vec_add(*dir, make_vec(0, change, 0));
		if (xyz == 2)
			*dir = vec_add(*dir, make_vec(0, 0, change));
	}
}

void	traverse_pl_translate(t_objects *obj, int xyz, double change)
{
	int		i;
	t_vec	*dir;

	i = -1;
	while (++i < obj->pl)
	{
		dir = &obj->planes[i].cor;
		if (xyz == 0)
			*dir = vec_add(*dir, make_vec(change, 0, 0));
		if (xyz == 1)
			*dir = vec_add(*dir, make_vec(0, change, 0));
		if (xyz == 2)
			*dir = vec_add(*dir, make_vec(0, 0, change));
	}
}

void	traverse_cy_translate(t_objects *obj, int xyz, double change)
{
	int		i;
	t_vec	*dir;

	i = -1;
	while (++i < obj->cy)
	{
		dir = &obj->cylinders[i].cor;
		if (xyz == 0)
			*dir = vec_add(*dir, make_vec(change, 0, 0));
		if (xyz == 1)
			*dir = vec_add(*dir, make_vec(0, change, 0));
		if (xyz == 2)
			*dir = vec_add(*dir, make_vec(0, 0, change));
	}
}
