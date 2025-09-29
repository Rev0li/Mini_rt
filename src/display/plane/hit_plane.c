/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:30:14 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/27 16:23:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

// void	hit_plane(t_plane plane, t_ray *ray, t_hit_objet *obj)
// {
// 	float	prod_scalaire;
// 	float	t;
// 	float	position;
// 	float	num;
//
// 	prod_scalaire = v_dot(ray->direction, plane.normal);
// 	if (fabs(prod_scalaire) < 0)
// 		return ;
// 	position = v_dot(plane.normal, plane.point);
// 	num = position - v_dot(ray->origin, plane.normal);
// 	t = num / prod_scalaire;
// 	if (t < 0) //1e-6
// 		return ;
// 	if (t < obj->dist)
// 	{
// 		obj->object = &plane;
// 		obj->dist = t;
// 	}
// 	return ;
// }
