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
 * SOUSTRACTION DE VECTEURS - ANALYSE COMPLÈTE
 * 
 * QU'EST-CE QUE LA SOUSTRACTION DE VECTEURS ?
 * ============================================
 * La soustraction de vecteurs permet de calculer le "déplacement"
 * nécessaire pour aller d'un point à un autre dans l'espace.
 * 
 * FORMULE MATHÉMATIQUE :
 * ======================
 * Si a = (ax, ay, az) et b = (bx, by, bz)
 * Alors a - b = (ax - bx, ay - by, az - bz)
 * 
 * INTERPRÉTATION GÉOMÉTRIQUE CRUCIALE :
 * =====================================
 * a - b = vecteur qui va du POINT b vers le POINT a
 * 
 * ATTENTION à l'ordre ! C'est contre-intuitif au début :
 * - Pour aller de B vers A, on calcule A - B
 * - Pour aller de A vers B, on calcule B - A
 * 
 * EXEMPLES CONCRETS :
 * ===================
 * 1) Points dans l'espace :
 *    Point A = (5, 7, 9)    Point B = (1, 2, 3)
 *    A - B = (4, 5, 6) → vecteur de B vers A
 *    B - A = (-4, -5, -6) → vecteur de A vers B (opposé)
 * 
 * 2) Exemple pratique en ray tracing :
 *    Caméra = (0, 0, 0)    Sphère = (10, 5, -3)
 *    Sphère - Caméra = (10, 5, -3) → direction de la caméra vers la sphère
 *    Caméra - Sphère = (-10, -5, 3) → direction de la sphère vers la caméra
 * 
 * CAS D'USAGE EN RAY TRACING :
 * ============================
 * - Calculer la direction d'un rayon : destination - origine
 * - Distance entre objets : position_objet1 - position_objet2
 * - Vecteurs normaux : point_surface - centre_objet
 * - Calculs d'éclairage : position_lumiere - point_surface
 * 
 * PROPRIÉTÉS MATHÉMATIQUES :
 * ==========================
 * - Non-commutative : a - b ≠ b - a (ordre important !)
 * - a - b = a + (-b) (soustraction = addition de l'opposé)
 * - a - a = (0, 0, 0) (vecteur nul)
 * - (a - b) + b = a (cohérence)
 */
t_vec3 v_sub(t_vec3 a, t_vec3 b)
{
    /*
     * IMPLÉMENTATION SIMPLE :
     * =======================
     * On soustrait chaque composante individuellement.
     * C'est l'équivalent de faire 3 soustractions scalaires séparées.
     * 
     * ÉTAPE PAR ÉTAPE :
     * =================
     * 1. Composante X : a.x - b.x
     * 2. Composante Y : a.y - b.y  
     * 3. Composante Z : a.z - b.z
     * 4. Construire le nouveau vecteur résultat
     * 
     * EXEMPLE DE CALCUL :
     * ===================
     * a = (5, 7, 9)  et  b = (1, 2, 3)
     * 
     * Composante X : 5 - 1 = 4
     * Composante Y : 7 - 2 = 5
     * Composante Z : 9 - 3 = 6
     * 
     * Résultat : (4, 5, 6)
     * 
     * VÉRIFICATION GÉOMÉTRIQUE :
     * ==========================
     * Si je place le vecteur (4, 5, 6) à partir du point B (1, 2, 3) :
     * Point final = B + résultat = (1, 2, 3) + (4, 5, 6) = (5, 7, 9) = A ✓
     * 
     * Cela confirme que notre vecteur va bien de B vers A !
     */
    
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
    
    /*
     * ALTERNATIVE PLUS EXPLICITE (pour la compréhension) :
     * ====================================================
     * double result_x = a.x - b.x;
     * double result_y = a.y - b.y; 
     * double result_z = a.z - b.z;
     * return vec3(result_x, result_y, result_z);
     * 
     * OPTIMISATIONS POSSIBLES :
     * =========================
     * Cette fonction est très simple et rapide.
     * Le compilateur optimisera probablement le code automatiquement.
     * Marquée 'inline' pour éviter l'overhead d'appel de fonction.
     */
}
