/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:33:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 15:40:48 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_vec3 get_sphere_normal(t_vec3 hit_point, t_sphere *sphere)
{
	t_vec3 normal;

	normal = v_sub(hit_point, sphere->center);
	normal = v_norm(normal);
	return (normal);
}
