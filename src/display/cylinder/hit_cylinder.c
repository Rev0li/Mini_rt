/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:31:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 14:59:49 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

// void assign_cylinder_dist(t_var_cylinder var, t_cylinder cylinder, t_hit_objet *obj, int i)
// {
//     var.t1 = (-var.b - sqrt(var.discriminant)) / (2 * var.a);
//     var.t2 = (-var.b + sqrt(var.discriminant)) / (2 * var.a);
//     var.tmin = fmin(var.t1, var.t2);
//     if (var.tmin > 0 && var.tmin < obj->dist)
//     {
//         var.point = set_vec(ray.ori)
//                         var.proj_to_cyl = v_dot(v_sub(, cylinder.center), cylinder.axis);
//     }
// }

void hit_cylinder(t_cylinder *cylinders, t_ray *ray, t_hit_objet *object, int nb_cylinders)
{
    t_var_cylinder var;
    int i;

    i = 0;
    var.x = v_sub(ray->origin, cylinders[i].center);
    while (i < nb_cylinders)
    {
        var.a = v_dot(ray->direction, ray->direction) - pow(v_dot(ray->direction, cylinders[i].axis), 2.);
        var.b = 2 * (v_dot(ray->direction, var.x) - (v_dot(ray->direction, cylinders[i].axis) * v_dot(var.x, cylinders[i].axis)));
        var.c = (v_dot(var.x, var.x) - pow(v_dot(var.x, cylinders[i].axis), 2.)) - pow(cylinders[i].diameter / 2, 2);
        var.discriminant = pow(var.b, 2.) - (4 * var.a * var.c);
        if (var.discriminant >= 0)
        {
            var.t1 = (-var.b - sqrt(var.discriminant)) / (2 * var.a);
            var.t2 = (-var.b + sqrt(var.discriminant)) / (2 * var.a);
            var.tmin = fmin(var.t1, var.t2);
            if (var.tmin > 0 && var.tmin < object->dist)
            {
                var.point = set_vec(ray->origin.x + (var.tmin * ray->direction.x), ray->origin.y + ray->direction.y * var.tmin, ray->origin.z + var.tmin * ray->direction.z);
                var.proj_to_cyl = v_dot(v_sub(var.point, cylinders[i].center), cylinders[i].axis);
                if (var.proj_to_cyl > 0 && var.proj_to_cyl <= cylinders[i].height)
                {
                    object->index = i;
                    object->dist = var.tmin;
                    object->form = CYLINDRE;
                }
            }
            // assign_cylinder_dist(var, cylinder, object, i);
        }
        i++;
    }
}
