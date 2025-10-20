/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:52:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 16:10:59 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

// #define AA_SAMPLES 2 // 2x2 = 4 sous-échantillons

t_hit_objet	hit_object(t_ray ray, t_scene scene)
{
t_hit_objet		obj;

	obj.dist = INFINITY;
	hit_plane(scene.planes, &ray, &obj, scene.nb_planes);
	hit_sphere(scene.spheres, &ray, &obj, scene.nb_spheres);
	hit_cylinder(scene.cylinders, &ray, &obj, scene.nb_cylinders);
	return (obj);
}

unsigned int	ray_color(t_ray ray, t_scene scene)
{
	unsigned int	ret_color;
	t_hit_objet		obj;

	obj = hit_object(ray, scene);
	if (obj.dist != INFINITY)
	{
		// ret_color = return_color_hex(obj, scene);
		ret_color = add_light(ray, scene, obj);
		return (ret_color);
	}
	return (000000);
}

// unsigned int	average_color(unsigned int *colors, int n)
// {
// 	float	r = 0, g = 0, b = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		r += (colors[i] >> 16) & 0xFF;
// 		g += (colors[i] >> 8) & 0xFF;
// 		b += colors[i] & 0xFF;
// 	}
// 	r /= n;
// 	g /= n;
// 	b /= n;
// 	return ((int)r << 16) | ((int)g << 8) | ((int)b);
// }
//
// unsigned int	compute_antialiased_pixel(int x, int y, t_mlx *data)
// {
// 	unsigned int	samples[AA_SAMPLES * AA_SAMPLES];
// 	int				i, j, index;
// 	float			sub_x, sub_y;
// 	float			offset;
// 	t_ray			ray;
//
// 	index = 0;
// 	offset = 1.0 / (AA_SAMPLES + 1);
// 	for (i = 0; i < AA_SAMPLES; i++)
// 	{
// 		for (j = 0; j < AA_SAMPLES; j++)
// 		{
// 			sub_x = x + (i + 0.5) * offset;
// 			sub_y = y + (j + 0.5) * offset;
// 			ray = create_ray_from_pixel(sub_x, sub_y, &data->scene.camera, data);
// 			samples[index++] = ray_color(ray, data->scene);
// 		}
// 	}
// 	return (average_color(samples, index));
// }
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
			// pixel_color = compute_antialiased_pixel(x, y, data);
			put_pixel(data, x, y, pixel_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
