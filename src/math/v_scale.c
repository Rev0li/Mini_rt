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
 * ============================================================================
 * FONCTION : v_scale (Vector Scale)
 * ============================================================================
 * 
 * DESCRIPTION :
 * Multiplie chaque composante d'un vecteur 3D par un scalaire (nombre réel).
 * Cette opération modifie la magnitude (longueur) du vecteur sans changer
 * sa direction (sauf si le scalaire est négatif, auquel cas la direction
 * est inversée).
 * 
 * PARAMÈTRES :
 * - a : vecteur 3D de type t_vec3 (contient les composantes x, y, z)
 * - s : scalaire de type double (nombre réel par lequel multiplier)
 * 
 * RETOUR :
 * - Un nouveau vecteur t_vec3 dont chaque composante est multipliée par s
 * 
 * EXEMPLES D'UTILISATION :
 * - v_scale(vec3(1, 2, 3), 2.0)   → vec3(2, 4, 6)    // double la longueur
 * - v_scale(vec3(1, 2, 3), 0.5)   → vec3(0.5, 1, 1.5) // divise par 2
 * - v_scale(vec3(1, 2, 3), -1.0)  → vec3(-1, -2, -3)  // inverse direction
 * - v_scale(vec3(1, 2, 3), 0.0)   → vec3(0, 0, 0)     // vecteur nul
 * 
 * APPLICATIONS DANS MINIRT :
 * - Ajustement de la taille des objets
 * - Calcul des directions de rayons
 * - Normalisation de vecteurs (avec s = 1/longueur)
 * - Calculs d'éclairage (atténuation de la lumière)
 * - Animation d'objets (scaling dynamique)
 * 
 * PROPRIÉTÉS MATHÉMATIQUES :
 * - Si s > 1 : le vecteur devient plus long
 * - Si 0 < s < 1 : le vecteur devient plus court
 * - Si s = 1 : le vecteur reste identique
 * - Si s = 0 : le vecteur devient le vecteur nul (0, 0, 0)
 * - Si s < 0 : le vecteur change de direction (180°) et de longueur
 */

t_vec3	v_scale(t_vec3 a, double s)
{
	// On applique la multiplication scalaire à chaque composante
	// du vecteur individuellement :
	
	// a.x * s : multiplie la composante X par le scalaire
	// a.y * s : multiplie la composante Y par le scalaire  
	// a.z * s : multiplie la composante Z par le scalaire
	
	// La fonction vec3() construit un nouveau vecteur avec ces
	// nouvelles composantes calculées
	
	return (vec3(a.x * s, a.y * s, a.z * s));
}

/*
 * ============================================================================
 * NOTES TECHNIQUES POUR LE PROJET MINIRT :
 * ============================================================================
 * 
 * 1. PERFORMANCE :
 *    - Cette fonction est très rapide (3 multiplications seulement)
 *    - Sera appelée fréquemment dans le ray tracing
 *    - Pas d'allocation mémoire dynamique
 * 
 * 2. PRÉCISION :
 *    - Utilise des doubles pour éviter les erreurs d'arrondi
 *    - Important pour les calculs de ray tracing précis
 * 
 * 3. UTILISATIONS TYPIQUES DANS MINIRT :
 *    
 *    a) Normalisation d'un vecteur :
 *       t_vec3 normalized = v_scale(vector, 1.0 / v_length(vector));
 *    
 *    b) Calcul de direction de rayon :
 *       t_vec3 ray_dir = v_scale(direction, distance);
 *    
 *    c) Atténuation de lumière :
 *       t_vec3 light_intensity = v_scale(light_color, attenuation_factor);
 *    
 *    d) Redimensionnement d'objet :
 *       t_vec3 scaled_sphere = v_scale(sphere_center, scale_factor);
 * 
 * 4. RELATION AVEC D'AUTRES FONCTIONS VECTORIELLES :
 *    - v_add() : addition de vecteurs
 *    - v_sub() : soustraction de vecteurs  
 *    - v_dot() : produit scalaire
 *    - v_cross() : produit vectoriel
 *    - v_length() : longueur du vecteur
 *    - v_normalize() : normalisation (utilise probablement v_scale)
 * 
 * 5. CAS PARTICULIERS À GÉRER :
 *    - s = 0 : résultat = vecteur nul
 *    - s très petit : peut causer des problèmes de précision
 *    - s très grand : risque d'overflow
 */
