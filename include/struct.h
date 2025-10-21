/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:52:42 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 17:55:16 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H
# define W_HEIGHT 1080
# define W_WIDTH 1300
# define M_PI 3.14159265358979323846
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

enum e_form_geo
{
	SPHERE,
	PLANE,
	CYLINDER,
	CIRCLE_TOP,
	CIRCLE_BOTTOM
};

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	hex;
}	t_color;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_ray_params
{
	double	new_x;
	double	new_y;
	float	aspect_ratio;
	float	rad_fov;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
}	t_ray_params;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	double	fov;
	bool	is_valid;
}	t_camera;

typedef struct s_light
{
	t_vec3	position;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_var_sphere
{
	float	t1;
	float	t2;
	float	a;
	float	b;
	float	c;
	t_vec3	oc;
	float	discriminant;
}	t_var_sphere;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	double	diameter;
	double	raduis;
	t_color	color;
}	t_sphere;

typedef struct s_var_plane
{
	float	prod_scalaire;
	float	t;
	float	position;
	float	num;
}	t_var_plane;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}	t_plane;

typedef struct s_var_circle
{
	double	denom;
	double	pos;
	double	res;
	double	num;
	t_vec3	circle_center;
	t_vec3	inter;
}	t_var_circle;

typedef struct s_var_cylinder
{
	double	t1;
	double	t2;
	double	a;
	double	b;
	double	c;
	double	tmin;
	t_vec3	x;
	double	proj_to_cyl;
	t_vec3	point;
	double	discriminant;
}	t_var_cylinder;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_hit_object
{
	int				index;
	float			dist;
	enum e_form_geo	form;
	bool			tangent;
	t_vec3			hit_point;
}	t_hit_objet;

typedef struct s_hit_cylinder_args
{
	t_cylinder	*cyl;
	t_ray		*ray;
	t_hit_objet	*obj;
	int			index;
}	t_hit_cylinder_args;

typedef struct s_hit_circle_args
{
	t_cylinder	*cylinder;
	t_ray		*ray;
	t_hit_objet	*obj;
	int			i;
	double		height;
	int			form;
}	t_hit_circle_args;

typedef struct s_light_vars
{
	t_vec3	hit_point;
	t_vec3	normal;
	t_vec3	light_dir;
	t_color	obj_color;
	t_color	final_color;
	float	amb_r;
	float	amb_g;
	float	amb_b;
	float	diff_int;
}	t_light_vars;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;

	t_sphere	*spheres;
	int			nb_spheres;
	int			sphere_index;

	t_plane		*planes;
	int			nb_planes;
	int			plane_index;

	t_cylinder	*cylinders;
	int			nb_cylinders;
	int			cylinder_index;

	bool		has_ambient;
	bool		has_camera;
	bool		has_light;
}	t_scene;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	t_scene	scene;
}	t_mlx;

#endif
