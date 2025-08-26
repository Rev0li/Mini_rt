/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:55:59 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:56:10 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * SOUSTRACTION DE VECTEURS
 * Soustrait le vecteur b du vecteur a
 * Exemple : vec3(5,7,9) - vec3(1,2,3) = vec3(4,5,6)
 * Géométriquement : donne le vecteur qui va de b vers a
 */
t_vec3 v_sub(t_vec3 a, t_vec3 b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

