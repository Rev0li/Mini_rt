/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:37:41 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/02 20:14:58 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"


unsigned int add_light(t_ray ray, t_scene scene, t_hit_objet obj)
{
	t_vec3 hit_point;
	t_vec3 normal;
	t_vec3 light_dir;
	t_color object_color;
	t_color final_color;
	float ambient_r, ambient_g, ambient_b;
	float diffuse_r, diffuse_g, diffuse_b;
	float diffuse_intensity;

	// 1. Calculer point et normale
	hit_point = get_hit_point(ray, obj.dist);
	normal = get_normal(hit_point, obj, scene);
	object_color = return_color(obj, scene);

	// 2. LUMIÈRE AMBIANTE
	ambient_r = object_color.r * scene.ambient.ratio * (scene.ambient.color.r / 255.0);
	ambient_g = object_color.g * scene.ambient.ratio * (scene.ambient.color.g / 255.0);
	ambient_b = object_color.b * scene.ambient.ratio * (scene.ambient.color.b / 255.0);

	// 3. LUMIÈRE SPOT (une seule)
	light_dir = get_light_direction(hit_point, scene.light);
	diffuse_intensity = calculate_diffuse(normal, light_dir);

	// 4. Vérifier les ombres
	if (is_in_shadow(hit_point, scene, light_dir, scene.light))
		diffuse_intensity = 0;

	// 5. Calculer diffuse
	diffuse_r = object_color.r * diffuse_intensity * 
		scene.light.brightness * (scene.light.color.r / 255.0);
	diffuse_g = object_color.g * diffuse_intensity * 
		scene.light.brightness * (scene.light.color.g / 255.0);
	diffuse_b = object_color.b * diffuse_intensity * 
		scene.light.brightness * (scene.light.color.b / 255.0);

	// 6. COMBINER et CLAMPER
	final_color.r = clamp(ambient_r + diffuse_r, 0, 255);
	final_color.g = clamp(ambient_g + diffuse_g, 0, 255);
	final_color.b = clamp(ambient_b + diffuse_b, 0, 255);

	final_color.hex = (final_color.r << 16) | (final_color.g << 8) | final_color.b;

	return (final_color.hex);
}
