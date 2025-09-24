/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:52:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/24 16:47:17 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_ray create_ray_from_pixel(int x, int y, t_camera *cam, t_mlx *data)
{
	t_ray ray;
	float aspect_ratio;
	float rad_fov;
	double new_x;
	double new_y;
	t_vec3 forward;
	t_vec3 fake_up;
	t_vec3 up;
	t_vec3 right;

	new_x = 2 * (x / (double)data->width) - 1;
	new_y = -(2 * (y / (double)data->height) - 1);
	aspect_ratio = (float)data->width / (float)data->height;
	rad_fov = cam->fov * (M_PI / 180);
	new_x = (new_x * aspect_ratio) * tan(rad_fov / 2);
	new_y = new_y * tan(rad_fov / 2);
	forward = set_vec(cam->orientation.x, cam->orientation.y, cam->orientation.z);
	forward = v_norm(forward);
	fake_up = set_vec(0, 1, 0);
	right = v_norm(v_cross(forward, fake_up));
	up = v_cross(forward, right);
	ray.origin = set_vec(cam->position.x, cam->position.y, cam->position.z);
	ray.direction = v_add(v_add(v_scale(right, new_x), v_scale(up, new_y)), forward);
	return (ray);
}

bool	hit_sphere(t_sphere sphere, t_ray *ray, float *dist)
{
	float	t1;
	float	t2;
	float	a;
	float	b;
	float	c;
	t_vec3	oc;
	float	discriminant;

	oc = v_sub(ray->origin, sphere.center);
	a = v_dot(ray->direction, ray->direction);
	b = 2 * v_dot(oc, ray->direction);
	c = v_dot(oc, oc) - ((sphere.diameter / 2) * (sphere.diameter / 2));
	discriminant = (b * b) - (4 * (a * c));
	if (discriminant < 0)
		return (false);
	else
	{
		t1 = ((-b + sqrt(discriminant)) / (2*a));
		t2 = ((-b - sqrt(discriminant)) / (2*a));
		if (t1 < t2)
			*dist = t1;
		else
			*dist = t2;
	}
	return (true);
}

unsigned int ray_color(t_ray ray, t_scene scene)
{
	float	dist_sphere;
	bool	h_sphere; 

	h_sphere = hit_sphere(scene.spheres[0], &ray, &dist_sphere);

	if (!h_sphere)
	{
		return (000000);
	}
	return (scene.spheres->color.hex);
}

void put_pixel(t_mlx *data, int x, int y, unsigned int pixel_color)
{
	int	offset;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return;
	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)(data->addr + offset) = pixel_color;
}
void	draw(t_mlx	*data)
{
	int				x;
	int				y;
	unsigned int	pixel_color;
	t_ray			ray;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			ray = create_ray_from_pixel(x, y, &data->scene.camera, data);
			pixel_color = ray_color(ray, data->scene);
			put_pixel(data, x, y, pixel_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
