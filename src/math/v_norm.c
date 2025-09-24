/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_norm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:32:36 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/24 15:43:55 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

t_vec3	v_norm(t_vec3 a)
{
	double len;
	t_vec3 vec;

	len = v_len(a);
	if (len == 0.0)
		return (a);
	vec.x = a.x / len;
	vec.y = a.y / len;
	vec.z = a.z / len;
	return (vec);
}
