/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:37:31 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:11 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_sphere	*realloc_sp(t_objects	*objects, int sp_count)
{
	t_sphere	*new_sphere;
	int			i;

	new_sphere = malloc(sizeof(t_sphere) * (sp_count + 1));
	if (!new_sphere)
	{
		printf("Error\nMalloc Failed");
		exit (1);
	}
	i = 0;
	while (i < sp_count)
	{
		new_sphere[i] = objects->spheres[i];
		i++;
	}
	if (sp_count != 0)
		free(objects->spheres);
	objects->spheres = new_sphere;
	return (&new_sphere[i]);
}

t_light	*realloc_light(t_scene *scene, int light_count)
{
	t_light	*new_light;
	int		i;

	new_light = malloc(sizeof(t_light) * (light_count + 1));
	if (!new_light)
	{
		printf("Error\nMalloc Failed");
		exit (1);
	}
	i = 0;
	while (i < light_count)
	{
		new_light[i] = scene->light[i];
		i++;
	}
	if (light_count != 0)
		free(scene->light);
	scene->light = new_light;
	return (&new_light[i]);
}

t_plane	*realloc_pl(t_objects *objects, int pl_count)
{
	t_plane	*new_plane;
	int		i;

	new_plane = malloc(sizeof(t_plane) * (pl_count + 1));
	if (!new_plane)
	{
		printf("Error\nMalloc Failed");
		exit (1);
	}
	i = 0;
	while (i < pl_count)
	{
		new_plane[i] = objects->planes[i];
		i++;
	}
	if (pl_count != 0)
		free(objects->planes);
	objects->planes = new_plane;
	return (&new_plane[i]);
}

t_cy	*realloc_cl(t_objects *objects, int cl_count)
{
	t_cy		*new_cylinder;
	int			i;

	new_cylinder = malloc(sizeof(t_cy) * (cl_count + 1));
	if (!new_cylinder)
	{
		printf("Error\nMalloc Failed");
		exit (1);
	}
	i = 0;
	while (i < cl_count)
	{
		new_cylinder[i] = objects->cylinders[i];
		i++;
	}
	if (cl_count != 0)
		free(objects->cylinders);
	objects->cylinders = new_cylinder;
	return (&new_cylinder[i]);
}
