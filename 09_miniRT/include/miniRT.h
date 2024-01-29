/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:25:14 by rtimsina          #+#    #+#             */
/*   Updated: 2024/01/26 19:01:24 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h> // for open
# include <stdlib.h>
# include <assert.h>
# include <string.h> //for strerror
# include <stdbool.h>

# include "../MLX42/include/MLX42/MLX42.h"
// # include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define WIDTH 640
# define HEIGHT 640
# define PI 3.14159265359
# define EPSILON 1e-6
// # define BPP sizeof(int32_t)
// # define MLX_ASSERT(cond, msg) assert(cond && msg);
// # define MLX_NONNULL(var) MLX_ASSERT(var, "Value can't be null"); 

//struct to represent vectors as one unit
typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_mat
{
	double	m[3][3];
}	t_mat;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_ray
{
	t_vec	dir;
	t_vec	orig;
}	t_ray;

typedef struct s_rec
{
	t_vec	point;
	t_vec	n_vec;
	double	tmin;
	double	tmax;
	double	t;
	t_color	albedo;
}	t_rec;

typedef struct s_disc
{
	double	a;
	double	b;
	double	c;
	double	disc;
}	t_disc;

typedef struct s_a_lighting
{
	double	l_ratio;
	t_color	color;
}	t_a_lighting;

typedef struct s_camera
{
	t_vec	orig;
	t_vec	dir;
	t_vec	left;
	double	viewport_h;
	double	viewport_w;
	t_vec	hori;
	t_vec	verti;
	double	fov;
	double	focal_len;
}	t_camera;

typedef struct s_light
{
	t_vec	cor;
	double	l_ratio;
	t_color	color;
}	t_light;

typedef struct s_sphere
{
	t_vec	cor;
	double	diam;
	t_color	color;
}	t_sphere;

typedef struct s_point_light
{
	t_color	diff;
	t_color	spec;
	t_vec	light_dir;
	t_vec	view_dir;
	t_vec	refl_dir;
	t_ray	light_ray;
	double	diff_fac;
	double	spec_amt;
	double	spec_exp;
	double	spec_fac;
}	t_point_light;

typedef struct s_plane
{
	t_vec	cor;
	t_vec	v_dir;
	t_color	color;
}	t_plane;

typedef struct s_cy
{
	t_vec	cor;
	t_vec	v_dir;
	double	diam;
	double	height;
	t_color	color;
}	t_cy;

typedef struct s_scene
{
	t_rec			rec;
	t_ray			ray;
	t_a_lighting	ambient;
	t_light			*light;
	int				lights_count;
	t_camera		camera;
}	t_scene;

typedef struct s_objects {
	t_sphere	*spheres;
	t_plane		*planes;
	t_cy		*cylinders;
	int			sp;
	int			pl;
	int			cy;
}	t_objects;

typedef struct s_mrt
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_a_lighting	*amb_light;
	t_light			*light;
	t_objects		objects;
	t_scene			scene;
}	t_mrt;

//*************************************//
//			parse						//
//*************************************//

//check_input.c
int			get_file(char *filename);
int			increment(int *num);
int			free_1(void *str);
int			valid_line(char *line, int *ca, int *cc);
int			valid_input(char *filename, t_mrt *mrt);

//check_element.c
int			valid_ambient(char *line);
int			valid_camera(char *line);
int			valid_light(char *line);

//check_objects.c
int			valid_sphere(char *line);
int			valid_plane(char *line);
int			valid_cylinder(char *line);

//get_field.c
int			fields_count(char **fields);
int			valid_check_field(char *field, double min, double max, int is_in);

//ft_atod.c
double		ft_atod(char *field);
char		*remove_whitespace(char *str);
int			in_range(double value, double min, double max);

//get_field.c
int			fields_count(char **fields);
int			valid_check_field(char *field, double min, double max, int is_in);
double		ret_num(double *dotcount, char *field, double range[3], int is_int);
double		get_num(char *field, double min, double max, int is_int);

//reallocs.c
t_sphere	*realloc_sp(t_objects *objects, int sp_count);
t_plane		*realloc_pl(t_objects *objects, int pl_count);
t_cy		*realloc_cl(t_objects *objects, int cl_count);
t_light		*realloc_light(t_scene *scene, int light_count);

//parse_scenes.c
void		parse_ambient(char **splitted, t_scene *scene);
void		parse_camera(char **splitted, t_scene *scene);
void		parse_light(char **splitted, t_scene *scene);
void		parse_line(char *line, t_scene *scene, t_objects *objects);

//putters.c
void		put_color(char *splitted, t_color *color);
void		put_coord(char *splitted, t_vec *point);
void		put_normal_vec(char *splitted, t_vec *vec);

//parse_objects.c
void		parse_sphere(char **splitted, t_objects *objects);
void		parse_plane(char **splitted, t_objects *objects);
void		parse_cylinder(char **splitted, t_objects *objects);

//*************************************//
//			utility						//
//*************************************//

//free.c
int			free_split(char **splitted);
void		err_msg(char *err_msg, char **splitted);

//put_pixel.c
void		put_pixel(mlx_image_t *img, int x, int y, int color);

//vec_calc1.c
t_vec		min_vec(t_vec vec1, t_vec vec2);
double		vec_len(t_vec vec);
t_vec		norm_vec(t_vec vec);
t_vec		scale_vec(t_vec vec, double s);
t_vec		cross_prod(t_vec vec1, t_vec vec2);

//vec_calc2.c
t_vec		vec_add(t_vec a, t_vec b);
t_vec		vec_sub(t_vec a, t_vec b);
t_vec		vec_scaled_div(t_vec vec, double t);
t_vec		vec_mult(t_vec a, t_vec b);

//vec_calc3.c
double		vec_dot(t_vec a, t_vec b);
double		square_vec(t_vec vec);

//ft_constructor.c
t_vec		make_vec(double x, double y, double z);
t_color		make_color(double x, double y, double z);
t_ray		make_ray(t_vec point, t_vec vec);
t_ray		make_view(t_camera *cam, double x, double y);

//utils.c
int			get_color(t_color c);
void		set_face_normal(t_ray *ray, t_rec *rec);
t_vec		ray_at(t_ray *ray, double t);
t_vec		reflect(t_vec light, t_vec normal);
int			in_shadow(t_objects *obj, t_ray *ray, t_rec rec, double light_len);
int			lighting(t_scene *scene, t_objects *obj);
void		check_hit(t_objects *obj, t_ray *ray, t_rec *rec);
int			color_obj(t_scene *scene, t_objects *obj);
t_color		point_light_get(t_scene *scene, t_light *light, t_objects *obj);

//init.c
void		camera_init(t_camera *cam);

//*************************************//
//		trace							//
//*************************************//

//ft_sphere.c
void		hit_sphere(t_sphere *sp, t_ray *ray, t_rec *rec);

//ft_plane.c
void		hit_plane(t_plane *pl, t_ray *ray, t_rec *rec);

//ft_cylinder.c
void		hit_cylinder_circle(t_cy *cy, t_ray *ray, t_rec *rec, double dir);
void		hit_cylinder_body(t_cy *cy, t_ray *ray, t_rec *rec);
void		update_cylinder_hit(t_cy *cy, t_ray *ray, t_rec *rec, double s);

//*************************************//
//		translate						//
//*************************************//

//rotate.c

void		camera_rotate_keys(t_mrt *mrt);
void		traverse_pl_rotate(t_objects *obj, int xyz, double change);

//rotate_calc.c
t_vec		rotate_y(t_vec vec, double angle);
t_vec		rotate_x(t_vec vec, double angle);
t_vec		rotate_z(t_vec vec, double angle);

//traverse.c
void		traverse_sp_translate(t_objects *obj, int xyz, double change);
void		traverse_pl_translate(t_objects *obj, int xyz, double change);
void		traverse_cy_translate(t_objects *obj, int xyz, double change);
void		traverse_cy_rotate(t_objects *obj, int xyz, double change);

//translate.c
void		camera_translate_keys(t_mrt *mrt);
void		light_translate_keys(t_mrt *mrt);
void		plane_keys(t_mrt *mrt);
void		cylinder_keys(t_mrt *mrt);
void		sphere_translate_keys(t_mrt *mrt);

#endif
