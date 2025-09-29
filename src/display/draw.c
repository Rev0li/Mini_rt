/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:52:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/27 16:23:16 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_hit_objet	hit_object(t_ray ray, t_scene scene)
{
	t_hit_objet		obj;

	obj.dist = INFINITY;
	// hit_plane(scene.planes[0], &ray, &obj);
	hit_sphere(scene.spheres, &ray, &obj, scene.nb_spheres);
	// hit_cylinder(scene.cylinders[0], &ray, &obj);
	return (obj);
}


unsigned int ray_color(t_ray ray, t_scene scene)
{
	unsigned int	ret_color;
	t_hit_objet		obj;

	obj = hit_object(ray, scene);
	if (obj.dist != INFINITY)
	{
		ret_color = obj.object.sphere->color.hex;
		// ret_color = calculate_color(ray, scene, obj);
		return (ret_color);
	}
	return (000000);
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
