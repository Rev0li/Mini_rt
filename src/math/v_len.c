/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:59:34 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 14:35:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

/*
 * LONGUEUR (MAGNITUDE) D'UN VECTEUR - ANALYSE DÉTAILLÉE
 * 
 * QU'EST-CE QUE LA LONGUEUR D'UN VECTEUR ?
 * ========================================
 * La longueur d'un vecteur est la distance entre :
 * - Le point d'origine (0, 0, 0)
 * - Le point final du vecteur (x, y, z)
 * 
 * C'est comme mesurer la longueur d'une flèche dans l'espace 3D.
 * 
 * EXEMPLES CONCRETS :
 * ===================
 * - Vecteur (3, 4, 0) → longueur = 5 (triangle rectangle classique 3-4-5)
 * - Vecteur (1, 0, 0) → longueur = 1 (vecteur unitaire sur l'axe X)
 * - Vecteur (1, 1, 1) → longueur = √3 ≈ 1.732
 * - Vecteur (0, 0, 0) → longueur = 0 (vecteur nul)
 * 
 * FORMULE MATHÉMATIQUE :
 * ======================
 * En 2D : longueur = √(x² + y²)        (théorème de Pythagore)
 * En 3D : longueur = √(x² + y² + z²)   (extension en 3D)
 * 
 * ASTUCE MATHÉMATIQUE UTILISÉE :
 * ===============================
 * Au lieu de calculer √(x² + y² + z²) directement,
 * on utilise le produit scalaire d'un vecteur avec lui-même :
 * 
 * a · a = a.x * a.x + a.y * a.y + a.z * a.z = x² + y² + z²
 * 
 * Donc : ||a|| = √(a · a)
 * 
 * AVANTAGES de cette approche :
 * - Code plus court et élégant
 * - Réutilise la fonction v_dot() qu'on a déjà écrite
 * - Moins de risques d'erreurs de frappe
 * - Plus facile à généraliser (marche en 2D, 3D, 4D...)
 */
 double v_len(t_vec3 a)
{
    // MÉTHODE DIRECTE (commentée) :
    // return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    
    // MÉTHODE AVEC PRODUIT SCALAIRE (plus élégante) :
    // v_dot(a, a) calcule a.x * a.x + a.y * a.y + a.z * a.z
    // sqrt() applique la racine carrée pour obtenir la longueur finale
    return sqrt(v_dot(a, a));
    
    /*
     * POURQUOI SQRT() ?
     * =================
     * Le théorème de Pythagore nous donne la longueur au carré : x² + y² + z²
     * Pour obtenir la longueur réelle, il faut prendre la racine carrée.
     * 
     * ATTENTION AUX PERFORMANCES :
     * ============================
     * sqrt() est une opération coûteuse en calcul.
     * Si on compare juste les longueurs (sans avoir besoin de la valeur exacte),
     * on peut comparer les carrés directement : v_dot(a, a) vs v_dot(b, b)
     */
}
