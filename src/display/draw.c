/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:01:28 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/20 18:02:14 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

// Dans src/display/draw.c
void put_pixel(t_mlx *data, int x, int y, int color)
{
    if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return;
    
	int offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)(data->addr + offset) = color;

}

void draw(t_mlx *data, t_scene scene)
{
// Parcours chaque pixel de la fenêtre
    for (int y = 0; y < W_HEIGHT; y++)
    {
        for (int x = 0; x < W_WIDTH; x++)
        {
            // 1. Calcule le rayon pour ce pixel (à implémenter)
            t_ray ray = calculate_ray(x, y, scene.camera);

            // 2. Détecte les intersections avec la sphère et le plan (à implémenter)
            t_color pixel_color = ray_color(ray, scene);

            // 3. Affiche le pixel
            int color = (pixel_color.r << 16) | (pixel_color.g << 8) | pixel_color.b;
            put_pixel(data, x, y, color);
        }
    }
    refresh_image(data);}

/*
Fonctions à implémenter (pour la caméra et les intersections)

calculate_ray
Calcule la direction du rayon pour un pixel (x, y) en utilisant la caméra.

Normalise x et y entre -1 et 1.
Utilise le FOV pour ajuster la direction.

ray_color
Détecte les intersections entre le rayon et les objets de la scène, et retourne la couleur correspondante.



Implémente calculate_ray pour générer un rayon par pixel.
Implémente ray_color pour détecter les intersections avec la sphère et le plan.
Teste l'affichage : tu devrais voir une sphère rouge sur un plan bleu !
*/
