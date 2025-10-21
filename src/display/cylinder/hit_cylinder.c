/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:31:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 14:40:59 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

static double	calc_discriminant(t_var_cylinder *v,
						t_cylinder *c, t_ray *r)
{
	v->x = v_sub(r->origin, c->center);
	v->a = v_dot(r->direction, r->direction)
		- pow(v_dot(r->direction, c->axis), 2.);
	v->b = 2 * (v_dot(r->direction, v->x)
			- (v_dot(r->direction, c->axis) * v_dot(v->x, c->axis)));
	v->c = (v_dot(v->x, v->x) - pow(v_dot(v->x, c->axis), 2.))
		- pow(c->diameter / 2, 2);
	return (pow(v->b, 2.) - (4 * v->a * v->c));
}

static double	get_tmin(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	if (t1 < 0 && t2 > 0)
		return (t2);
	if (t1 > 0 && t2 < 0)
		return (t1);
	return (-1);
}

static void	update_hit(t_hit_cylinder_args a, t_var_cylinder *v)
{
	v->point = set_vec(a.ray->origin.x + v->tmin * a.ray->direction.x,
			a.ray->origin.y + v->tmin * a.ray->direction.y,
			a.ray->origin.z + v->tmin * a.ray->direction.z);
	v->proj_to_cyl = v_dot(v_sub(v->point, a.cyl->center), a.cyl->axis);
	if (v->proj_to_cyl <= a.cyl->height / 2
		&& v->proj_to_cyl >= -a.cyl->height / 2)
	{
		a.obj->index = a.index;
		a.obj->dist = v->tmin;
		a.obj->form = CYLINDER;
	}
}

void	hit_cylinder(t_cylinder *cyls, t_ray *ray,
			t_hit_objet *obj, int nb)
{
	t_var_cylinder		v;
	t_hit_cylinder_args	a;
	int					i;

	i = 0;
	while (i < nb)
	{
		a.cyl = &cyls[i];
		a.ray = ray;
		a.obj = obj;
		a.index = i;
		v.discriminant = calc_discriminant(&v, a.cyl, a.ray);
		if (v.discriminant >= 0)
		{
			v.t1 = (-v.b - sqrt(v.discriminant)) / (2 * v.a);
			v.t2 = (-v.b + sqrt(v.discriminant)) / (2 * v.a);
			v.tmin = get_tmin(v.t1, v.t2);
			if (v.tmin > 0 && v.tmin < obj->dist)
				update_hit(a, &v);
		}
		i++;
	}
}
