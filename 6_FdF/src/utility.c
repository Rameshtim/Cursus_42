/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 03:46:00 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/21 16:43:34 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*fdf_init(char *name)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, name, true);
	if (!fdf->mlx)
		return (NULL);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		return (NULL);
	fdf->map = NULL;
	fdf->rgb = BLACK;
	fdf->line_rgb = SILVER;
	return (fdf);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

int	ft_isblank(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
