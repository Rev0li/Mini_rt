/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:27:27 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 17:04:38 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_vec3	get_cylinder_normal(t_vec3 hit_point, t_cylinder *cylinder)
{
	t_vec3	normal;
	double	projection;

	normal = v_sub(hit_point, cylinder->center);
	projection = v_dot(normal, cylinder->axis);
	normal = v_sub(normal, v_scale(cylinder->axis, projection));
	return (v_norm(normal));
}
