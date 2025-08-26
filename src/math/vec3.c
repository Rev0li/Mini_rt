/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:56:42 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:56:51 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * CONSTRUCTEUR DE VECTEUR 3D
 * Crée un vecteur 3D à partir de 3 coordonnées (x, y, z)
 * C'est comme créer un point dans l'espace 3D
 */
t_vec3 vec3(double x, double y, double z) {
    return (t_vec3){x, y, z};
}

