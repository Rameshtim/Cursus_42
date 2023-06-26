/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:38:50 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/05 17:20:14 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*pt_new(float height, uint32_t color)
{
	t_point	*pt;

	pt = malloc(sizeof(t_point));
	if (!pt)
		ft_error("malloc error");
	pt->height = height;
	pt->color = color;
	pt->next = NULL;
	pt->last = pt;
	return (pt);
}

void	pt_add_back(t_point *dst, t_point *new)
{
	if (!dst || !new)
		ft_error("list error");
	dst->last->next = new;
	dst->last = new;
}

void	pt_clear(t_point *pt)
{
	t_point	*tmp;

	while (pt)
	{
		tmp = pt;
		pt = pt->next;
		free(tmp);
	}
}

t_point	*next_row_pt(t_point *pt, int cols)
{
	int		i;

	i = 0;
	while (i < cols)
	{
		if (pt->next)
			pt = pt->next;
		i++;
	}
	return (pt);
}
