/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:34:40 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 13:47:57 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	get_file(char *filename)
{
	int	len;
	int	fd;

	fd = 0;
	len = ft_strlen(filename);
	if (len < 3 && printf("Error\nFilename too small"))
		return (-1);
	if (ft_strcmp(filename + len - 3, ".rt"))
	{
		printf("Error\nInvalid file extension\n");
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCould not open file");
		return (-1);
	}
	return (fd);
}

int	increment(int *num)
{
	*num += 1;
	return (1);
}

int	valid_line(char *line, int *ca, int *cc)
{
	if (ft_strlen(line) == 1 && line[0] == '\n')
		return (1);
	else if (!ft_strncmp(line, "A ", 2) && increment(ca))
		return (valid_ambient(line));
	else if (!ft_strncmp(line, "C ", 2) && increment(cc))
		return (valid_camera(line));
	else if (!ft_strncmp(line, "L ", 2))
		return (valid_light(line));
	else if (!ft_strncmp(line, "sp ", 3))
		return (valid_sphere(line));
	else if (!ft_strncmp(line, "pl ", 3))
		return (valid_plane(line));
	else if (!ft_strncmp(line, "cy ", 3))
		return (valid_cylinder(line));
	else
		printf("Error\nWrong Element Type\n");
	return (0);
}

int	free_1(void *str)
{
	free(str);
	return (1);
}

int	valid_input(char *filename, t_mrt *mrt)
{
	int		fd;
	char	*line;
	int		ct[2];

	ct[0] = 0;
	ct[1] = 0;
	fd = get_file(filename);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!valid_line(line, &ct[1], &ct[0]) && free_1(line) && !close(fd))
			return (0);
		if ((ct[0] == 2 || ct[1] == 2) && !close(fd))
			return (printf("Error\nDouble declaration\n"), 0);
		if (line[0] != '\n')
			parse_line(line, &mrt->scene, &mrt->objects);
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (1);
}
