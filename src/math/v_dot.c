/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:55:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:55:29 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * PRODUIT SCALAIRE (DOT PRODUCT)
 * Retourne UN NOMBRE (pas un vecteur !)
 * Formule : a.x*b.x + a.y*b.y + a.z*b.z
 * Propriétés importantes :
 * - Si résultat = 0 : les vecteurs sont perpendiculaires
 * - Si résultat > 0 : angle aigu entre les vecteurs
 * - Si résultat < 0 : angle obtus entre les vecteurs
 */
double v_dot(t_vec3 a, t_vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

