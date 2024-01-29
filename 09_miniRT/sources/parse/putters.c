/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:06:12 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 20:14:56 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	put_color(char *splitted, t_color *color)
{
	char	**rgb;

	splitted = remove_whitespace(splitted);
	rgb = ft_split(splitted, ',');
	if (!rgb)
		err_msg("Malloc Failed", rgb);
	color->r = ft_atod(rgb[0]) / 255.0;
	color->g = ft_atod(rgb[1]) / 255.0;
	color->b = ft_atod(rgb[2]) / 255.0;
	free_split(rgb);
}

void	put_coord(char *splitted, t_vec *point)
{
	char	**crd;

	splitted = remove_whitespace(splitted);
	crd = ft_split(splitted, ',');
	if (!crd)
		err_msg("Malloc Failed\n", crd);
	point->x = ft_atod(crd[0]);
	point->y = ft_atod(crd[1]);
	point->z = ft_atod(crd[2]);
	free_split(crd);
}

void	put_normal_vec(char *splitted, t_vec *vec)
{
	char	**dir;

	splitted = remove_whitespace(splitted);
	dir = ft_split(splitted, ',');
	if (!dir)
		err_msg("Malloc Failed\n", dir);
	vec->x = ft_atod(dir[0]);
	vec->y = ft_atod(dir[1]);
	vec->z = ft_atod(dir[2]);
	*vec = norm_vec(*vec);
	free_split(dir);
}
