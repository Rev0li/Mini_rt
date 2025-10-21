/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:33:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 16:42:13 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	clamp(float value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return ((int)value);
}

float	calculate_diffuse(t_vec3 normal, t_vec3 light_dir)
{
	float	intensity;

	intensity = v_dot(normal, light_dir);
	if (intensity < 0)
		intensity = 0;
	return (intensity);
}

bool	is_in_shadow(t_vec3 hit_point, t_scene scene,
				t_vec3 light_dir, t_light light)
{
	t_ray		shadow_ray;
	t_hit_objet	shadow_obj;
	float		light_distance;

	shadow_ray.origin = v_add(hit_point, v_scale(light_dir, 0.01));
	shadow_ray.direction = light_dir;
	light_distance = v_len(v_sub(light.position, hit_point));
	shadow_obj = hit_object(shadow_ray, scene);
	if (shadow_obj.dist < light_distance && shadow_obj.dist != INFINITY)
		return (true);
	return (false);
}

t_vec3	get_light_direction(t_vec3 hit_point, t_light light)
{
	t_vec3	light_dir;

	light_dir = v_sub(light.position, hit_point);
	light_dir = v_norm(light_dir);
	return (light_dir);
}
