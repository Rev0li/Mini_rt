/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_from_pixel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:21:22 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/27 15:21:47 by okientzl         ###   ########.fr       */
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
