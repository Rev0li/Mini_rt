/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_cross.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:54:39 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:55:02 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * PRODUIT VECTORIEL (CROSS PRODUCT)
 * Retourne un vecteur perpendiculaire aux deux vecteurs d'entrée
 * Direction donnée par la "règle de la main droite"
 * Utilisé pour calculer des normales de surface ou des bases orthogonales
 */
t_vec3 v_cross(t_vec3 a, t_vec3 b) {
    return vec3(
        a.y * b.z - a.z * b.y,  // composante X
        a.z * b.x - a.x * b.z,  // composante Y
        a.x * b.y - a.y * b.x   // composante Z
    );
}

