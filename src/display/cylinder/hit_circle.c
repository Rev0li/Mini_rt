/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:34:53 by yassinefahf       #+#    #+#             */
/*   Updated: 2025/10/21 16:59:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void hit_circle_top(t_cylinder *cylinder, t_ray *ray, t_hit_objet *obj, int i)
{
	double denom;
	double pos;
	double res;
	double num;
	t_vec3 circle_center;
	t_vec3 inter;

	circle_center = v_add(cylinder->center, v_scale(cylinder->axis, cylinder->height / 2));
	denom = v_dot(ray->direction, cylinder->axis);
	if (fabs(denom) > 1e-6)
	{
		pos = v_dot(cylinder->axis, circle_center);
		num = pos - v_dot(ray->origin, cylinder->axis);
		res = num / denom;
		if (res > 0 && res < obj->dist)
		{
			inter = set_vec(ray->origin.x + res * ray->direction.x, ray->origin.y + res * ray->direction.y, ray->origin.z + res * ray->direction.z);
			if (distance(circle_center, inter) <= cylinder->diameter / 2)
			{
				obj->index = i;
				obj->dist = res;
				obj->form = CIRCLE_TOP;
			}
		}
	}
}

void hit_circle_bottom(t_cylinder *cylinder, t_ray *ray, t_hit_objet *obj, int i)
{
	double denom;
	double pos;
	double res;
	double num;
	t_vec3 circle_center;
	t_vec3 inter;

	circle_center = v_add(cylinder->center, v_scale(cylinder->axis, -cylinder->height / 2));
	denom = v_dot(ray->direction, cylinder->axis);
	if (fabs(denom) > 1e-6)
	{
		pos = v_dot(cylinder->axis, circle_center);
		num = pos - v_dot(ray->origin, cylinder->axis);
		res = num / denom;
		if (res > 0 && res < obj->dist)
		{
			inter = set_vec(ray->origin.x + res * ray->direction.x, ray->origin.y + res * ray->direction.y, ray->origin.z + res * ray->direction.z);
			if (distance(circle_center, inter) <= cylinder->diameter / 2)
			{
				obj->index = i;
				obj->dist = res;
				obj->form = CIRCLE_BOTTOM;
			}
		}
	}
}

void hit_circle(t_cylinder *cylindre, t_ray *ray, t_hit_objet *obj, int nb_cylinders)
{
	int i;

	i = 0;
	while (i < nb_cylinders)
	{
		hit_circle_top(&cylindre[i], ray, obj, i);
		hit_circle_bottom(&cylindre[i], ray, obj, i);
		i++;
	}
}
