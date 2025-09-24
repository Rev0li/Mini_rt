/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:52:42 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/24 11:20:22 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H


#define W_HEIGHT 900
#define W_WIDTH 1200
# define M_PI 3.14159265358979323846

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_vec3
{
    double x;
    double y;
    double z;
} t_vec3;

typedef struct s_color
{
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
	unsigned int	hex;
} t_color;

typedef struct s_ray
{
    t_vec3 origin;
    t_vec3 direction;
} t_ray;

typedef struct s_ambient
{
    double ratio;
    t_color color;
} t_ambient;

typedef struct s_camera
{
    t_vec3 position;
    t_vec3 orientation;
    double fov;
} t_camera;

typedef struct s_light
{
    t_vec3 position;
    double brightness;
    t_color color;
} t_light;

typedef struct s_sphere
{
    t_vec3 center;
    double radius;
	double diameter;
    t_color color;
} t_sphere;

typedef struct s_plane
{
    t_vec3 point;
    t_vec3 normal;
    t_color color;
} t_plane;

typedef struct s_cylinder
{
    t_vec3 center;
    t_vec3 axis;
    double diameter;
    double height;
    t_color color;
} t_cylinder;


typedef struct s_scene
{
    t_ambient ambient;
    t_camera camera;

    t_light light;
    int nb_lights;

    t_sphere *spheres;
    int nb_spheres;
    int sphere_index;

    t_plane *planes;
    int nb_planes;
    int plane_index;

    t_cylinder *cylinders;
    int nb_cylinders;
    int cylinder_index;

    bool has_ambient;
    bool has_camera;
    bool has_light;
} t_scene;

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
