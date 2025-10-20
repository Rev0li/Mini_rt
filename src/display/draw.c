/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:52:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 14:30:12 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_hit_objet hit_object(t_ray ray, t_scene scene)
{
	t_hit_objet obj;

	obj.dist = INFINITY;
	hit_plane(scene.planes, &ray, &obj, scene.nb_planes);
	hit_sphere(scene.spheres, &ray, &obj, scene.nb_spheres);
	hit_cylinder(scene.cylinders, &ray, &obj, scene.nb_cylinders);
	return (obj);
}

unsigned int ray_color(t_ray ray, t_scene scene)
{
	unsigned int ret_color;
	t_hit_objet obj;

	obj = hit_object(ray, scene);
	if (obj.dist != INFINITY)
	{
		// ret_color = return_color_hex(obj, scene);
		ret_color = add_light(ray, scene, obj);
		return (ret_color);
	}
	return (000000);
}

void draw(t_mlx *data)
{
	int x;
	int y;
	unsigned int pixel_color;
	t_ray ray;

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
