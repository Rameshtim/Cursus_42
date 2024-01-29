/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scenes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:47:41 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/25 19:37:24 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	parse_ambient(char **splitted, t_scene *scene)
{
	t_a_lighting	*ambient;

	ambient = &scene->ambient;
	ambient->l_ratio = ft_atod(splitted[1]);
	put_color(splitted[2], &ambient->color);
}

void	parse_camera(char **splitted, t_scene *scene)
{
	t_camera	*camera;

	camera = &scene->camera;
	put_coord(splitted[1], &camera->orig);
	put_normal_vec(splitted[2], &camera->dir);
	camera->fov = ft_atod(splitted[3]);
}

void	parse_light(char **splitted, t_scene *scene)
{
	t_light	*light;

	light = realloc_light(scene, scene->lights_count);
	scene->lights_count++;
	put_coord(splitted[1], &light->cor);
	light->l_ratio = ft_atod(splitted[2]);
	put_color(splitted[3], &light->color);
}

void	parse_line(char *line, t_scene *scene, t_objects *objects)
{
	char	**split;

	line = remove_whitespace(line);
	split = ft_split(line, ' ');
	if (!split)
		err_msg("Malloc Failed", split);
	if (!ft_strncmp(split[0], "A", 1))
		parse_ambient(split, scene);
	else if (!ft_strncmp(split[0], "C", 1))
		parse_camera(split, scene);
	else if (!ft_strncmp(split[0], "L", 1))
		parse_light(split, scene);
	else if (!ft_strncmp(split[0], "sp", 2))
		parse_sphere(split, objects);
	else if (!ft_strncmp(split[0], "pl", 2))
		parse_plane(split, objects);
	else if (!ft_strncmp(split[0], "cy", 2))
		parse_cylinder(split, objects);
	free_split(split);
}
