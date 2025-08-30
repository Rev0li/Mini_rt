/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:01:28 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/30 16:05:25 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

/*****************************************************************************/
/*                    CONSTRUCTION DU RAYON À TRAVERS UN PIXEL              */
/*****************************************************************************/

/*
 * FONCTION CENTRALE DU RAY TRACING !
 * 
 * Pour chaque pixel de l'écran, on doit calculer un RAYON qui part de la caméra
 * et passe par ce pixel. Ce rayon va ensuite "voyager" dans la scène 3D pour
 * déterminer quelle couleur afficher.
 *
 * MODÈLE DE CAMÉRA "PINHOLE" (sténopé) :
 * - La caméra est un point dans l'espace
 * - Devant elle, il y a un "écran virtuel" (le plan image)
 * - Chaque pixel de notre fenêtre correspond à un point sur cet écran virtuel
 * - Le rayon va de la caméra vers ce point sur l'écran virtuel
 *
 * PARAMÈTRES :
 * - px, py : coordonnées du pixel dans la fenêtre (0,0 = coin haut-gauche)
 * - cam : informations sur la caméra (position, orientation, champ de vision)
 */
t_ray calculate_ray(int px, int py, t_camera cam)
{
    t_ray	ray;
	double	aspect;
    
    // RATIO D'ASPECT : largeur/hauteur de l'écran
    // Important pour éviter la déformation des objets ronds
    aspect = (double)W_WIDTH / (double)W_HEIGHT;

    /*
     * CONSTRUCTION DE LA BASE ORTHONORMÉE DE LA CAMÉRA
     * 
     * On a besoin de 3 vecteurs perpendiculaires pour définir l'orientation :
     * - forward : direction où regarde la caméra
     * - right : direction "droite" de la caméra
     * - up : direction "haut" de la caméra
     */
    
    // 1. Direction principale : où regarde la caméra (donnée par l'utilisateur)
    t_vec3 forward = v_norm(cam.orientation);
    
    // 2. Direction "haut" du monde (convention : axe Y vers le haut)
    t_vec3 world_up = vec3(0.0, 1.0, 0.0);
    
    // 3. Direction "droite" : produit vectoriel forward × world_up
    // Le produit vectoriel donne un vecteur perpendiculaire aux deux autres
    t_vec3 right = v_norm(v_cross(forward, world_up));
    
    // 4. Direction "haut" caméra : produit vectoriel right × forward
    // On recalcule pour avoir une base parfaitement orthogonale
    t_vec3 up = v_norm(v_cross(right, forward));

    /*
     * CALCUL DE LA TAILLE DE L'ÉCRAN VIRTUEL
     * 
     * Le champ de vision (FOV) détermine "à quel point la caméra voit large"
     * - FOV petit = zoom, vision étroite
     * - FOV grand = grand angle, vision large
     */
    
    // Demi-hauteur de l'écran virtuel à distance 1 de la caméra
    // tan(FOV/2) donne la tangente de la moitié de l'angle
    double half_height = tan(deg2rad(cam.fov) * 0.5);
    
    // Demi-largeur : proportionnelle à la hauteur selon le ratio d'aspect
    double half_width = aspect * half_height;

    /*
     * CONVERSION PIXEL → COORDONNÉES ÉCRAN VIRTUEL
     * 
     * On convertit les coordonnées pixel (px, py) en coordonnées
     * sur l'écran virtuel (u, v) dans l'intervalle [-1, 1]
     */
    
    // u : position horizontale sur l'écran virtuel [-1, 1]
    // +0.5 pour viser le CENTRE du pixel (pas le coin)
    // Division par largeur pour normaliser [0, 1]
    // ×2 - 1 pour passer à [-1, 1]
    double u = ((px + 0.5) / (double)W_WIDTH) * 2.0 - 1.0;
    
    // v : position verticale sur l'écran virtuel [-1, 1]
    // ATTENTION : inversion de Y car les pixels (0,0) sont en haut-gauche
    // mais on veut que l'écran virtuel ait Y positif vers le haut
    double v = 1.0 - ((py + 0.5) / (double)W_HEIGHT) * 2.0;

    /*
     * POSITION FINALE SUR L'ÉCRAN VIRTUEL
     * 
     * On passe des coordonnées normalisées [-1, 1] aux vraies coordonnées
     * en unités "monde" sur l'écran virtuel
     */
    double sx = u * half_width;   // position X sur l'écran virtuel
    double sy = v * half_height;  // position Y sur l'écran virtuel

    /*
     * CONSTRUCTION DU RAYON FINAL
     * 
     * Rayon = point d'origine + direction
     * - Origine : position de la caméra dans l'espace
     * - Direction : vecteur normalisé qui va de la caméra vers le point (sx, sy)
     *               sur l'écran virtuel
     */
    ray.origin = cam.position;
    
    // Direction = combinaison des 3 vecteurs de base de la caméra
    // sx * right : déplacement horizontal sur l'écran
    // sy * up : déplacement vertical sur l'écran
    // forward : avancer vers l'écran (distance focale = 1)
    ray.direction = v_norm(v_add(v_add(v_scale(right, sx), v_scale(up, sy)), forward));
    
    return ray;
}

/*****************************************************************************/
/*                        INTERSECTIONS GÉOMÉTRIQUES                        */
/*****************************************************************************/

/*
 * INTERSECTION RAYON-SPHÈRE
 * 
 * PROBLÈME : étant donné un rayon et une sphère, déterminer s'ils se croisent
 * et à quelle distance de l'origine du rayon.
 * 
 * MÉTHODE MATHÉMATIQUE :
 * - Rayon : point = origine + t × direction (t = distance parcourue)
 * - Sphère : tous les points à distance R du centre
 * - Intersection : résoudre ||origine + t × direction - centre|| = rayon
 * 
 * Cela donne une équation du second degré en t : at² + bt + c = 0
 */
static bool hit_sphere(const t_sphere *sp, const t_ray *r, double *out_t)
{
    // Vecteur du centre de la sphère vers l'origine du rayon
    t_vec3 oc = v_sub(r->origin, sp->center);
    
    // Coefficients de l'équation quadratique at² + bt + c = 0
    // Si la direction du rayon est normalisée, alors a = 1
    double a = v_dot(r->direction, r->direction);  // ||direction||²
    double b = 2.0 * v_dot(oc, r->direction);      // 2 × (oc · direction)  
    double c = v_dot(oc, oc) - sp->radius * sp->radius;  // ||oc||² - R²

    // Discriminant : détermine le nombre de solutions
    double disc = b * b - 4.0 * a * c;
    
    // Si discriminant < 0 : pas de solution réelle = pas d'intersection
    if (disc < 0.0) 
        return false;

    // Calcul des deux solutions (intersections)
    double sqrtD = sqrt(disc);
    double t1 = (-b - sqrtD) / (2.0 * a);  // intersection la plus proche
    double t2 = (-b + sqrtD) / (2.0 * a);  // intersection la plus lointaine

    // On ne veut que les intersections "devant" la caméra (t > 0)
    // et pas trop près pour éviter les artefacts numériques
    const double eps = 1e-4;  // seuil minimum pour éviter l'auto-intersection
    
    // Choisir la bonne intersection : la plus proche qui soit valide
    double t = (t1 > eps) ? t1 : ((t2 > eps) ? t2 : -1.0);
    
    if (t < 0.0) 
        return false;  // Aucune intersection valide

    *out_t = t;  // Retourner la distance de l'intersection
    return true;
}

/*
 * INTERSECTION RAYON-PLAN
 * 
 * PROBLÈME : étant donné un rayon et un plan, déterminer s'ils se croisent.
 * 
 * MÉTHODE MATHÉMATIQUE :
 * - Plan défini par : un point sur le plan + vecteur normal
 * - Équation du plan : (point - point_plan) · normale = 0
 * - Rayon : origine + t × direction
 * - Intersection : substituer le rayon dans l'équation du plan
 */
static bool hit_plane(const t_plane *pl, const t_ray *r, double *out_t)
{
    // Le dénominateur nous dit si le rayon est parallèle au plan
    double denom = v_dot(pl->normal, r->direction);
    
    const double eps_parallel = 1e-6;
    // Si denom ≈ 0, le rayon est (presque) parallèle au plan
    if (fabs(denom) < eps_parallel) 
        return false;  // Pas d'intersection utile

    // Calcul de la distance t le long du rayon
    // Formule : t = (point_plan - origine_rayon) · normale / (direction_rayon · normale)
    double t = v_dot(v_sub(pl->point, r->origin), pl->normal) / denom;
    
    const double eps = 1e-4;
    // On ne veut que les intersections devant la caméra
    if (t <= eps) 
        return false;  // Derrière la caméra ou trop proche

    *out_t = t;
    return true;
}

/*****************************************************************************/
/*                           CALCUL DE COULEUR DU RAYON                     */
/*****************************************************************************/

/*
 * FONCTION PRINCIPALE DU RAY TRACING
 * 
 * Pour un rayon donné, déterminer quelle couleur il "voit"
 * 
 * ALGORITHME SIMPLIFIÉ (sans éclairage) :
 * 1. Tester toutes les intersections possibles avec les objets de la scène
 * 2. Garder l'intersection la plus proche (plus petit t > 0)
 * 3. Retourner la couleur de base de cet objet
 * 4. Si aucune intersection : couleur de fond
 * 
 * NOTE : Cette version est volontairement simple pour valider la géométrie.
 * Plus tard, on ajoutera l'éclairage, les ombres, les réflexions, etc.
 */
t_color ray_color(t_ray ray, t_scene scene)
{
    double t_sph, t_pl;  // Distances des intersections
    
    // Tester l'intersection avec la sphère
    bool hit_s = hit_sphere(scene.spheres, &ray, &t_sph);
    
    // Tester l'intersection avec le plan  
    bool hit_p = hit_plane(scene.planes, &ray, &t_pl);

    // Si aucune intersection : couleur de fond
    if (!hit_s && !hit_p) {
        // Ici on retourne du noir, mais on pourrait faire :
        // - Un dégradé de ciel (bleu en haut, blanc en bas)
        // - Une couleur unie
        // - Une skybox (texture panoramique)
        return (t_color){0, 0, 0};
    }

    /*
     * SÉLECTION DE L'INTERSECTION LA PLUS PROCHE
     * 
     * Si plusieurs objets sont intersectés par le rayon, on ne voit que
     * celui qui est le plus proche de la caméra (plus petit t).
     * C'est le principe de "test de profondeur" (Z-buffer).
     */
    if (hit_s && (!hit_p || t_sph < t_pl)) {
        // La sphère est plus proche (ou seule intersectée)
        return scene.spheres->color;
    } else {
        // Le plan est plus proche (ou seul intersecté)
        return scene.planes->color;
    }
}

/*****************************************************************************/
/*                              RENDU À L'ÉCRAN                             */
/*****************************************************************************/

/*
 * PLACEMENT D'UN PIXEL DANS L'IMAGE
 * 
 * Cette fonction écrit directement dans la mémoire de l'image miniLibX.
 * Elle utilise les calculs qu'on a discutés ensemble !
 */
void put_pixel(t_mlx *data, int x, int y, int color)
{
	int	offset;
    // Vérification des limites : ne pas écrire en dehors de l'image
    if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
        return;
    
    // CALCUL DE L'OFFSET DANS LE TABLEAU LINÉAIRE
    // Comme on l'a vu : position = (ligne × taille_ligne) + (colonne × octets_par_pixel)
    offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
    
    // ÉCRITURE DIRECTE EN MÉMOIRE
    // On cast vers unsigned int* pour écrire les 4 octets d'un coup
    // miniLibX gère automatiquement l'ordre BGRA vs RGBA
    *(unsigned int*)(data->addr + offset) = color;
}

/*
 * FONCTION PRINCIPALE DE RENDU
 * 
 * C'EST LE CŒUR DU RAY TRACER !
 * 
 * ALGORITHME :
 * Pour chaque pixel de l'écran :
 *   1. Calculer le rayon qui passe par ce pixel
 *   2. Déterminer quelle couleur ce rayon "voit" dans la scène
 *   3. Afficher cette couleur sur le pixel
 * 
 * Cette approche s'appelle "ray casting" ou "ray tracing".
 * Elle simule le chemin inverse de la lumière : au lieu de suivre 
 * les photons de la source vers l'œil, on suit les rayons de l'œil 
 * vers les objets.
 */
void draw(t_mlx *data, t_scene scene)
{
    // DOUBLE BOUCLE : parcourir tous les pixels de l'écran
    // y = lignes (de haut en bas)
    // x = colonnes (de gauche à droite)
	int		y;
	int		x;
	t_ray	ray;
	t_color	pixel_color;
	int		color;
	y = 0;
	x = 0;

	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
            /*
             * ÉTAPE 1 : CALCUL DU RAYON
             * Pour ce pixel (x, y), quel rayon part de la caméra ?
             */
            ray = calculate_ray(x, y, scene.camera);

            /*
             * ÉTAPE 2 : INTERSECTION ET COULEUR
             * Ce rayon croise-t-il des objets ? Lesquels ? Quelle couleur ?
             */
            pixel_color = ray_color(ray, scene);

            /*
             * ÉTAPE 3 : CONVERSION COULEUR
             * Convertir notre structure t_color en entier pour miniLibX
             * Format : 0x00RRGGBB (hexadécimal)
             * - Rouge sur 8 bits décalé de 16 positions (bits 23-16)
             * - Vert sur 8 bits décalé de 8 positions (bits 15-8) 
             * - Bleu sur 8 bits (bits 7-0)
             */
            color = (pixel_color.r << 16) | (pixel_color.g << 8) | pixel_color.b;

            /*
             * ÉTAPE 4 : AFFICHAGE
             * Placer le pixel coloré dans notre image en mémoire
             */
            put_pixel(data, x, y, color);    
			x++;
		}
		y++;
	}

    /*
     * ÉTAPE 5 : RAFRAÎCHISSEMENT
     * Afficher l'image complète sur la fenêtre
     * (Cette fonction doit copier l'image mémoire vers l'écran)
     */
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
