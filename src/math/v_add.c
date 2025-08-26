/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:56:20 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:56:30 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * ADDITION DE VECTEURS
 * Additionne deux vecteurs composante par composante
 * Exemple : vec3(1,2,3) + vec3(4,5,6) = vec3(5,7,9)
 * Géométriquement : "bout à bout", on déplace d'un vecteur puis de l'autre
 */
t_vec3 v_add(t_vec3 a, t_vec3 b) {
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

