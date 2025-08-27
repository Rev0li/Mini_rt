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
 * ============================================================================
 * FONCTION : v_dot (Vector Dot Product - Produit Scalaire)
 * ============================================================================
 * 
 * DESCRIPTION :
 * Calcule le produit scalaire de deux vecteurs 3D. Le produit scalaire est
 * une opération fondamentale qui retourne UN NOMBRE (pas un vecteur !).
 * Ce nombre nous renseigne sur l'angle entre les deux vecteurs et leur
 * "alignement" relatif.
 * 
 * FORMULE MATHÉMATIQUE :
 * dot(a, b) = a.x * b.x + a.y * b.y + a.z * b.z
 * 
 * Alternative avec angle : dot(a, b) = |a| * |b| * cos(θ)
 * où θ est l'angle entre les vecteurs a et b
 * 
 * PARAMÈTRES :
 * - a : premier vecteur 3D de type t_vec3
 * - b : second vecteur 3D de type t_vec3
 * 
 * RETOUR :
 * - Un double représentant le produit scalaire (nombre réel, PAS un vecteur)
 * 
 * INTERPRÉTATION DU RÉSULTAT :
 * - résultat = 0  : vecteurs perpendiculaires (angle = 90°)
 * - résultat > 0  : angle aigu (< 90°) - vecteurs "dans la même direction"
 * - résultat < 0  : angle obtus (> 90°) - vecteurs "en opposition"
 * - résultat = |a|*|b| : vecteurs parallèles (angle = 0°)
 * - résultat = -|a|*|b| : vecteurs antiparallèles (angle = 180°)
 * 
 * EXEMPLES CONCRETS :
 * - v_dot(vec3(1,0,0), vec3(0,1,0)) = 0    // axes X et Y perpendiculaires
 * - v_dot(vec3(1,0,0), vec3(1,0,0)) = 1    // même vecteur (angle 0°)
 * - v_dot(vec3(1,0,0), vec3(-1,0,0)) = -1  // vecteurs opposés (angle 180°)
 * - v_dot(vec3(1,1,0), vec3(1,0,0)) = 1    // angle 45° (résultat positif)
 * - v_dot(vec3(3,4,0), vec3(4,3,0)) = 24   // même direction générale
 */

double	v_dot(t_vec3 a, t_vec3 b)
{
	// On multiplie composante par composante, puis on additionne :
	// - a.x * b.x : contribution des composantes X
	// - a.y * b.y : contribution des composantes Y  
	// - a.z * b.z : contribution des composantes Z
	// La somme de ces trois produits donne le produit scalaire
	
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/*
 * ============================================================================
 * APPLICATIONS CRITIQUES DANS MINIRT :
 * ============================================================================
 * 
 * 1. DÉTECTION DE COLLISION ET INTERSECTION :
 *    - Calcul d'intersections rayon-plan
 *    - Détermination de la face visible d'un objet
 *    - Test de proximité entre objets
 * 
 * 2. CALCULS D'ÉCLAIRAGE (TRÈS IMPORTANT) :
 *    a) Loi de Lambert (éclairage diffus) :
 *       intensity = max(0, v_dot(normal_surface, direction_lumiere))
 *    
 *    b) Éclairage spéculaire (reflets) :
 *       specular = pow(max(0, v_dot(reflect_vector, view_vector)), shininess)
 *    
 *    c) Détection face éclairée/face dans l'ombre :
 *       if (v_dot(normal, light_dir) > 0) // face éclairée
 *           // appliquer éclairage
 *       else // face dans l'ombre
 *           // appliquer ombre
 * 
 * 3. CALCULS GÉOMÉTRIQUES :
 *    - Distance d'un point à un plan : v_dot(point - point_plan, normale_plan)
 *    - Projection d'un vecteur sur un autre
 *    - Test d'orientation (devant/derrière la caméra)
 * 
 * 4. OPTIMISATIONS DE PERFORMANCE :
 *    - Frustum culling (éliminer objets hors champ de vision)
 *    - Backface culling (ne pas rendre les faces arrière)
 *    - Tests de visibilité rapides
 */

/*
 * ============================================================================
 * EXEMPLES D'USAGE DANS MINIRT :
 * ============================================================================
 */

/*
 * EXEMPLE 1 : Calcul d'intensité lumineuse diffuse
 * 
 * double	calculate_diffuse_lighting(t_vec3 surface_normal, t_vec3 light_direction)
 * {
 *     double	dot_product;
 *     
 *     dot_product = v_dot(surface_normal, light_direction);
 *     if (dot_product < 0)
 *         return (0.0); // Face dans l'ombre
 *     return (dot_product); // Intensité proportionnelle à l'angle
 * }
 */

/*
 * EXEMPLE 2 : Test de visibilité d'une face (backface culling)
 * 
 * int	is_face_visible(t_vec3 face_normal, t_vec3 view_direction)
 * {
 *     return (v_dot(face_normal, view_direction) < 0);
 *     // Si négatif, la face est tournée vers nous (visible)
 *     // Si positif, la face nous tourne le dos (non visible)
 * }
 */

/*
 * EXEMPLE 3 : Intersection rayon-sphère (utilise le produit scalaire)
 * 
 * double	ray_sphere_intersection(t_vec3 ray_origin, t_vec3 ray_dir, 
 *                                 t_vec3 sphere_center, double sphere_radius)
 * {
 *     t_vec3	oc = v_sub(ray_origin, sphere_center);
 *     double	a = v_dot(ray_dir, ray_dir);        // ||ray_dir||²
 *     double	b = 2.0 * v_dot(oc, ray_dir);      // 2 * oc · ray_dir
 *     double	c = v_dot(oc, oc) - sphere_radius * sphere_radius;
 *     
 *     // Résoudre l'équation quadratique a*t² + b*t + c = 0
 *     // pour trouver les points d'intersection
 * }
 */

/*
 * ============================================================================
 * PROPRIÉTÉS MATHÉMATIQUES IMPORTANTES :
 * ============================================================================
 * 
 * 1. COMMUTATIVITÉ :
 *    v_dot(a, b) = v_dot(b, a)
 * 
 * 2. DISTRIBUTIVITÉ :
 *    v_dot(a, b + c) = v_dot(a, b) + v_dot(a, c)
 * 
 * 3. ASSOCIATIVITÉ AVEC SCALAIRE :
 *    v_dot(k * a, b) = k * v_dot(a, b)
 * 
 * 4. RELATION AVEC LA LONGUEUR :
 *    v_dot(a, a) = |a|² (carré de la longueur du vecteur)
 * 
 * 5. CALCUL D'ANGLE :
 *    cos(θ) = v_dot(a, b) / (|a| * |b|)
 *    donc : θ = acos(v_dot(a, b) / (|a| * |b|))
 */

/*
 * ============================================================================
 * NOTES DE PERFORMANCE POUR 42 :
 * ============================================================================
 * 
 * 1. RAPIDITÉ :
 *    - Seulement 3 multiplications + 2 additions
 *    - Une des opérations les plus rapides en calcul vectoriel
 *    - Appelée TRÈS fréquemment dans le ray tracing
 * 
 * 2. PRÉCISION :
 *    - Utilise des doubles pour éviter les erreurs d'arrondi
 *    - Crucial pour les tests d'intersection précis
 * 
 * 3. OPTIMISATIONS POSSIBLES :
 *    - Pré-normaliser les vecteurs quand c'est possible
 *    - Éviter les calculs redondants dans les boucles
 *    - Utiliser pour des tests rapides avant calculs complexes
 * 
 * 4. CAS LIMITES :
 *    - Vecteurs nuls : résultat = 0
 *    - Vecteurs très petits : risque de perte de précision
 *    - Pour calculer des angles, vérifier que les vecteurs ne sont pas nuls
 */
