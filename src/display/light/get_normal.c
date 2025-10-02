/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:22:10 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 15:37:06 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_vec3 get_normal(t_vec3 hit_point, t_hit_objet obj, t_scene scene)
{
    if (obj.form == SPHERE)
        return (get_sphere_normal(hit_point, &scene.spheres[obj.index]));
    else if (obj.form == PLANE)
        return (v_norm(scene.planes[obj.index].normal));
    // else if (obj.form == CYLINDER)
    //     return (get_cylinder_normal(hit_point, obj.object.cylinder));
    
    return ((t_vec3){0, 1, 0}); // valeur par défaut
}
