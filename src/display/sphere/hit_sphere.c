/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:29:41 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/27 16:23:14 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

void	assign_dist(t_var_sphere var, t_hit_objet *obj, int i)
{
	var.t1 = ((-var.b + sqrt(var.discriminant)) / (2 * var.a));
	var.t2 = ((-var.b - sqrt(var.discriminant)) / (2 * var.a));
	if (var.t2 > 0 && var.t2 < obj->dist)
	{
		obj->index = i;
		obj->dist = var.t2;
		obj->form = SPHERE;
	}
	else if (var.t1 > 0 && var.t1 < obj->dist)
	{
		obj->index = i;
		obj->dist = var.t1;
		obj->form = SPHERE;
	}
}

void	hit_sphere(t_sphere *sphere, t_ray *ray,
				t_hit_objet *obj, int nb_spheres)
{
	t_var_sphere	var;
	int				i;

	i = 0;
	while (i < nb_spheres)
	{
		sphere[i].radius = sphere[i].diameter / 2;
		var.oc = v_sub(ray->origin, sphere[i].center);
		var.a = v_dot(ray->direction, ray->direction);
		var.b = 2 * v_dot(var.oc, ray->direction);
		var.c = v_dot(var.oc, var.oc) - (sphere[i].radius * sphere[i].radius);
		var.discriminant = (var.b * var.b) - (4 * (var.a * var.c));
		if (var.discriminant > 0)
		{
			assign_dist(var, obj, i);
		}
		i++;
	}
	return ;
}
