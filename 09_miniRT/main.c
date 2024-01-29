/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhan <kzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:16:46 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 15:40:50 by kzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

static void	draw(t_mrt	*mrt)
{
	int		x;
	int		y;
	double	u;
	double	v;
	t_scene	*scene;

	scene = &mrt->scene;
	camera_init(&mrt->scene.camera);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			u = (double)x / (WIDTH - 1);
			v = (double)(HEIGHT - 1 - y) / (HEIGHT - 1);
			scene->ray = make_view(&scene->camera, u, v);
			mrt->scene.rec.tmax = 99999;
			mrt->scene.rec.tmin = EPSILON;
			put_pixel(mrt->img, x, y, color_obj(scene, &mrt->objects));
		}
	}
}

static void	free_objects(t_objects *objects, t_scene *scene)
{
	if (objects->sp)
		free(objects->spheres);
	if (objects->pl)
		free(objects->planes);
	if (objects->cy)
		free(objects->cylinders);
	if (scene->light)
		free(scene->light);
}

static void	key_press(void *param)
{
	t_mrt	*mrt;

	mrt = param;
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_ESCAPE))
	{
		free_objects(&mrt->objects, &mrt->scene);
		mlx_delete_image(mrt->mlx, mrt->img);
		mlx_terminate(mrt->mlx);
		exit (0);
	}
	camera_rotate_keys(mrt);
	sphere_translate_keys(mrt);
	camera_translate_keys(mrt);
	light_translate_keys(mrt);
	plane_keys(mrt);
	cylinder_keys(mrt);
	draw(mrt);
}

static void	print_text(t_mrt mrt)
{
	mlx_put_string(mrt.mlx, "Light Translate: 1 - 6", 20, 20);
	mlx_put_string(mrt.mlx, "Plane Translate: 7 8 9 0 - =", 20, 100);
	mlx_put_string(mrt.mlx, "Camera Translate: E R T Y U I ", 20, 60);
	mlx_put_string(mrt.mlx, "Camera Rotate: UP, Down, Left, Right", 20, 40);
	mlx_put_string(mrt.mlx, "Cylinder Rotate: J K L M , .", 20, 120);
	mlx_put_string(mrt.mlx, "Plane Rotate: A S D F G H", 20, 80);
	mlx_put_string(mrt.mlx, "Sphere Translate: Q W O P [ ]", 20, 140);
}

int	main(int argc, char **argv)
{
	t_mrt	mrt;

	mrt = (t_mrt){0};
	if (argc != 2 || !valid_input(argv[1], &mrt))
		return (1);
	mrt.mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!mrt.mlx)
		return (1);
	mrt.img = mlx_new_image(mrt.mlx, WIDTH, HEIGHT);
	if (!mrt.img)
		return (1);
	mlx_image_to_window(mrt.mlx, mrt.img, 0, 0);
	mlx_loop_hook(mrt.mlx, &key_press, &mrt);
	draw(&mrt);
	print_text(mrt);
	mlx_loop(mrt.mlx);
	mlx_delete_image(mrt.mlx, mrt.img);
	mlx_terminate(mrt.mlx);
	free_objects(&mrt.objects, &mrt.scene);
	return (0);
}
