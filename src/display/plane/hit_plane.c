/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:30:14 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/09 18:28:29 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void hit_plane(t_plane *plane, t_ray *ray, t_hit_objet *obj, int nb_planes)
{
	t_var_plane var;
	int i;

	i = 0;
	while (i < nb_planes)
	{
		var.prod_scalaire = v_dot(ray->direction, plane[i].normal);
		if (fabs(var.prod_scalaire) > 1e-6)
		{
			var.position = v_dot(plane[i].normal, plane[i].point);
			var.num = var.position - v_dot(ray->origin, plane[i].normal);
			var.t = var.num / var.prod_scalaire;
			if (var.t > 0 && var.t < obj->dist)
			{
				obj->index = i;
				obj->dist = var.t;
				obj->form = PLANE;
			}
		}
		i++;
	}
	return;
}
