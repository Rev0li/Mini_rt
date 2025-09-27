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

void	hit_sphere(t_sphere sphere, t_ray *ray, t_hit_objet *obj)
{
	float	t1;
	float	t2;
	float	a;
	float	b;
	float	c;
	t_vec3	oc;
	float	discriminant;

	oc = v_sub(ray->origin, sphere.center);
	a = v_dot(ray->direction, ray->direction);
	b = 2 * v_dot(oc, ray->direction);
	c = v_dot(oc, oc) - ((sphere.diameter / 2) * (sphere.diameter / 2));
	discriminant = (b * b) - (4 * (a * c));
	if (discriminant < 0)
		return ;
	else
	{
		obj->object = &sphere;
		t1 = ((-b + sqrt(discriminant)) / (2*a));
		t2 = ((-b - sqrt(discriminant)) / (2*a));
		if (t1 < t2)
			obj->dist = t1;
		else
			obj->dist = t2;
	}
	return ;
}
