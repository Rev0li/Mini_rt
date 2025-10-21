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

t_vec3 get_cylinder_normal(t_vec3 hit_point, t_cylinder *cylinder)
{
    t_vec3 normal;
    double projection;

    normal = v_sub(hit_point, cylinder->center);
    projection = v_dot(normal, cylinder->axis);
    normal = v_sub(normal, v_scale(cylinder->axis, projection));
    return (v_norm(normal));
}

void hit_cylinder(t_cylinder *cylinders, t_ray *ray, t_hit_objet *object, int nb_cylinders)
{
    t_var_cylinder var;
    int i;

    i = 0;
    while (i < nb_cylinders)
    {
        var.x = v_sub(ray->origin, cylinders[i].center);
        var.a = v_dot(ray->direction, ray->direction) - pow(v_dot(ray->direction, cylinders[i].axis), 2.);
        var.b = 2 * (v_dot(ray->direction, var.x) - (v_dot(ray->direction, cylinders[i].axis) * v_dot(var.x, cylinders[i].axis)));
        var.c = (v_dot(var.x, var.x) - pow(v_dot(var.x, cylinders[i].axis), 2.)) - pow(cylinders[i].diameter / 2, 2);
        var.discriminant = pow(var.b, 2.) - (4 * var.a * var.c);
        if (var.discriminant >= 0)
        {
            var.t1 = (-var.b - sqrt(var.discriminant)) / (2 * var.a);
            var.t2 = (-var.b + sqrt(var.discriminant)) / (2 * var.a);
            var.tmin = -1;
            if (var.t1 > 0 && var.t2 > 0)
                var.tmin = fmin(var.t1, var.t2);
            if (var.t1 < 0 && var.t2 > 0)
                var.tmin = var.t2;
            else if (var.t1 > 0 && var.t2 < 0)
                var.tmin = var.t1;
            if (var.tmin > 0 && var.tmin < object->dist)
            {
                var.point = set_vec(ray->origin.x + (var.tmin * ray->direction.x), ray->origin.y + ray->direction.y * var.tmin, ray->origin.z + var.tmin * ray->direction.z);
                var.proj_to_cyl = v_dot(v_sub(var.point, cylinders[i].center), cylinders[i].axis);
                if (var.proj_to_cyl <= cylinders[i].height / 2 && var.proj_to_cyl >= -cylinders[i].height / 2)
                {
                    object->index = i;
                    object->dist = var.tmin;
                    object->form = CYLINDRE;
                }
            }
        }
        i++;
    }
}
