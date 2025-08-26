/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg2rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:54:07 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 13:54:30 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"
/*
 * CONVERSION DEGRÉS VERS RADIANS
 * Les fonctions mathématiques (sin, cos, tan) utilisent les radians
 * Formule : radians = degrés × π/180
 */
double deg2rad(double d) {
    return d * (M_PI / 180.0);
}
