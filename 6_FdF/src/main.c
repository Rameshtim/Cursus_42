/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 03:38:00 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/05 17:25:43 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *error_msg)
{
	if (errno)
		perror("ERROR");
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	ft_put_instructions(t_fdf *fdf)
{
	int32_t	x;
	int32_t	y;

	x = 10;
	y = 10;
	mlx_put_string(fdf->mlx, "Instructions:", x, y);
	mlx_put_string(fdf->mlx, "Move Map:		W/A/S/D", x, y += 20);
	mlx_put_string(fdf->mlx, "Zoom:			Q/E", x, y += 20);
	mlx_put_string(fdf->mlx, "Color:			1-5", x, y += 20);
	mlx_put_string(fdf->mlx, "Change Height:	Page UP/Down", x, y += 20);
}

static void	fdf(char *file_name)
{
	t_fdf		*fdf;
	mlx_image_t	*img;
	int			fd;

	fdf = fdf_init("FdF");
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		ft_error (ERR_FD);
	fdf->map = parse(fdf, fd);
	close (fd);
	if (!fdf || !fdf->map)
		ft_error(ERR_INIT);
	img = fdf->img;
	draw(fdf, fdf->map);
	mlx_image_to_window(fdf->mlx, img, 0, 0);
	ft_put_instructions(fdf);
	mlx_loop_hook(fdf->mlx, &hook, fdf);
	mlx_loop_hook(fdf->mlx, &close_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	exit(EXIT_SUCCESS);
}

int32_t	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			fdf(argv[1]);
		else
			ft_error(ERR_FILE_EXTENSION);
	}
	else
		ft_error(ERR_FILE);
	return (0);
}
