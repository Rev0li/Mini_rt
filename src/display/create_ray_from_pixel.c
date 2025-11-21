/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_from_pixel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:21:22 by okientzl          #+#    #+#             */
/*   Updated: 2025/11/21 15:05:16 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

t_ray create_ray_from_pixel(int x, int y, t_camera *cam, t_mlx *data)
{
	t_ray ray;
	t_ray_params p;

	p.new_x = 2 * (x / (double)data->width) - 1;
	p.new_y = -(2 * (y / (double)data->height) - 1);
	p.aspect_ratio = (float)data->width / (float)data->height;
	p.rad_fov = cam->fov * (M_PI / 180);
	p.new_x *= p.aspect_ratio * tan(p.rad_fov / 2);
	p.new_y *= tan(p.rad_fov / 2);
	p.forward = v_norm(set_vec(cam->orientation.x,
							   cam->orientation.y, cam->orientation.z));
	if (fabs(p.forward.y) > 0.999)
		p.right = v_norm(v_cross(p.forward, set_vec(0, 0, 1)));
	else
		p.right = v_norm(v_cross(p.forward, set_vec(0, 1, 0)));
	p.up = v_cross(p.right, p.forward);
	ray.origin = set_vec(cam->position.x, cam->position.y, cam->position.z);
	ray.direction = v_add(v_add(v_scale(p.right, p.new_x),
								v_scale(p.up, p.new_y)),
						  p.forward);
	return (ray);
}
