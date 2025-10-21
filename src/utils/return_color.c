/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:10:18 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 17:55:20 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

unsigned int	return_color_hex(t_hit_objet obj, t_scene scene)
{
	unsigned int	color;

	if (obj.form == SPHERE)
		color = scene.spheres[obj.index].color.hex;
	if (obj.form == PLANE)
		color = scene.planes[obj.index].color.hex;
	if (obj.form == CYLINDER
		|| obj.form == CIRCLE_TOP
		|| obj.form == CIRCLE_BOTTOM)
		color = scene.cylinders[obj.index].color.hex;
	return (color);
}

t_color	return_color(t_hit_objet obj, t_scene scene)
{
	t_color	color;

	if (obj.form == SPHERE)
		color = scene.spheres[obj.index].color;
	if (obj.form == PLANE)
		color = scene.planes[obj.index].color;
	if (obj.form == CYLINDER
		|| obj.form == CIRCLE_TOP
		|| obj.form == CIRCLE_BOTTOM)
		color = scene.cylinders[obj.index].color;
	return (color);
}
