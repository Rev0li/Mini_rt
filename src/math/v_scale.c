/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:55:37 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:55:50 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * MULTIPLICATION PAR UN SCALAIRE
 * Multiplie chaque composante du vecteur par le même nombre
 * Exemple : vec3(1,2,3) * 2 = vec3(2,4,6)
 * Géométriquement : change la longueur du vecteur (direction identique)
 */
t_vec3 v_scale(t_vec3 a, double s) {
    return vec3(a.x * s, a.y * s, a.z * s);
}

