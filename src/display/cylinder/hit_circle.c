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

static void	hit_caps(t_hit_circle_args args)
{
	t_var_circle	var;

	var.circle_center = v_add(args.cylinder->center,
			v_scale(args.cylinder->axis, args.height));
	var.denom = v_dot(args.ray->direction, args.cylinder->axis);
	if (fabs(var.denom) > 1e-6)
	{
		var.pos = v_dot(args.cylinder->axis, var.circle_center);
		var.num = var.pos - v_dot(args.ray->origin, args.cylinder->axis);
		var.res = var.num / var.denom;
		if (var.res > 0 && var.res < args.obj->dist)
		{
			var.inter = set_vec(
					args.ray->origin.x + var.res * args.ray->direction.x,
					args.ray->origin.y + var.res * args.ray->direction.y,
					args.ray->origin.z + var.res * args.ray->direction.z);
			if (distance(var.circle_center, var.inter)
				<= args.cylinder->diameter / 2)
			{
				args.obj->index = args.i;
				args.obj->dist = var.res;
				args.obj->form = args.form;
			}
		}
	}
}

void	hit_circle_top(t_cylinder *cylinder,
					t_ray *ray, t_hit_objet *obj, int i)
{
	t_hit_circle_args	args;

	args.cylinder = cylinder;
	args.ray = ray;
	args.obj = obj;
	args.i = i;
	args.height = cylinder->height / 2;
	args.form = CIRCLE_TOP;
	hit_caps(args);
}

void	hit_circle_bottom(t_cylinder *cylinder,
					t_ray *ray, t_hit_objet *obj, int i)
{
	t_hit_circle_args	args;

	args.cylinder = cylinder;
	args.ray = ray;
	args.obj = obj;
	args.i = i;
	args.height = -cylinder->height / 2;
	args.form = CIRCLE_BOTTOM;
	hit_caps(args);
}

void	hit_circle(t_cylinder *cylindre, t_ray *ray,
				t_hit_objet *obj, int nb_cylinders)
{
	int	i;

	i = 0;
	while (i < nb_cylinders)
	{
		hit_circle_top(&cylindre[i], ray, obj, i);
		hit_circle_bottom(&cylindre[i], ray, obj, i);
		i++;
	}
}
