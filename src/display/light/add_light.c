/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:37:41 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 17:55:21 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

static void	calc_ambient(t_light_vars *v, t_scene s)
{
	v->amb_r = v->obj_color.r * s.ambient.ratio
		* (s.ambient.color.r / 255.0);
	v->amb_g = v->obj_color.g * s.ambient.ratio
		* (s.ambient.color.g / 255.0);
	v->amb_b = v->obj_color.b * s.ambient.ratio
		* (s.ambient.color.b / 256.0);
}

static void	calc_diffuse(t_light_vars *v, t_scene s)
{
	float	dr;
	float	dg;
	float	db;

	dr = s.light.color.r / 255.0;
	dg = s.light.color.g / 255.0;
	db = s.light.color.b / 255.0;
	v->final_color.r = v->obj_color.r * v->diff_int
		* s.light.brightness * dr;
	v->final_color.g = v->obj_color.g * v->diff_int
		* s.light.brightness * dg;
	v->final_color.b = v->obj_color.b * v->diff_int
		* s.light.brightness * db;
}

unsigned int	add_light(t_ray ray, t_scene s, t_hit_objet obj)
{
	t_light_vars	v;

	v.hit_point = get_hit_point(ray, obj.dist);
	v.normal = get_normal(v.hit_point, obj, s);
	v.obj_color = return_color(obj, s);
	calc_ambient(&v, s);
	v.light_dir = get_light_direction(v.hit_point, s.light);
	v.diff_int = calculate_diffuse(v.normal, v.light_dir);
	if (is_in_shadow(v.hit_point, s, v.light_dir, s.light))
		v.diff_int = 0;
	calc_diffuse(&v, s);
	v.final_color.r = clamp(v.amb_r + v.final_color.r, 0, 255);
	v.final_color.g = clamp(v.amb_g + v.final_color.g, 0, 255);
	v.final_color.b = clamp(v.amb_b + v.final_color.b, 0, 255);
	return ((v.final_color.r << 16)
		| (v.final_color.g << 8)
		| v.final_color.b);
}
