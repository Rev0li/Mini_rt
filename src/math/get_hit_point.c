/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:49:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 15:46:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_vec3	get_hit_point(t_ray ray, float distance)
{
	t_vec3	hit_point;

	hit_point = v_add(ray.origin, v_scale(ray.direction, distance));
	return (hit_point);
}
