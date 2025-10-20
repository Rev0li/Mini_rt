/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:27:27 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/02 20:14:59 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_vec3 v_mult(t_vec3 v, double s)
{
	t_vec3 result;
	result.x = v.x * s;
	result.y = v.y * s;
	result.z = v.z * s;
	return result;
}

t_vec3 get_cylinder_normal(t_vec3 hit_point, t_cylinder *cylinder)
{
	t_vec3	to_hit;
	double	projection_length;
	t_vec3	projection;

	to_hit = v_sub(hit_point, cylinder->center);  // Vecteur du centre du cylindre au point d'impact
	projection_length = v_dot(to_hit, cylinder->axis);  // Projection du vecteur sur l'axe du cylindre
	projection = v_mult(cylinder->axis, projection_length);  // Vecteur projection sur l'axe
	return (v_norm(v_sub(to_hit, projection)));  // Normalise le vecteur pour obtenir une direction unitaire
}
