/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:31:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/27 15:33:16 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

// Retourne 1 si le point est dans la portion valide du cylindre (hauteur)
int in_cylinder_height(t_cylinder cylinder, t_vec3 hit_point)
{
    // Projection du vecteur hit_point - center sur l'axe
    double proj = v_dot(v_sub(hit_point, cylinder.center), cylinder.axis);
    double demi_hauteur = cylinder.height / 2.0;
    // Test si dans [ -h/2, +h/2 ]
    return (proj >= -demi_hauteur && proj <= demi_hauteur);
}

// Fonction utilitaire pour assigner la distance et les données de l'objet
bool assign_dist_cy(t_var_cylinder var, t_hit_objet *obj, t_cylinder cylinder, t_ray *ray)
{

    var.t1 = ((-var.b + sqrt(var.discriminant)) / (2 * var.a));
    var.t2 = ((-var.b - sqrt(var.discriminant)) / (2 * var.a));

	if (var.discriminant == 0)
	{
		var.t1 = (-var.b) / (2 * var.a);
		obj->hit_point = v_add(ray->origin, v_scale(ray->direction, var.t1));
		if (var.t1 >= 0 && var.t1 < obj->dist && in_cylinder_height(cylinder, obj->hit_point))
		{
        obj->dist = var.t1;
        obj->form = CYLINDER;
		return true;
		}
	}
    // On vérifie la validité des intersections et on met à jour l'objet
    if (var.t2 > 0 && var.t2 < obj->dist)
    {
		obj->hit_point = v_add(ray->origin, v_scale(ray->direction, var.t2));
		if (in_cylinder_height(cylinder, obj->hit_point))
		{
        obj->dist = var.t2;
        obj->form = CYLINDER;
		return true;
		}
    }
    else if (var.t1 > 0 && var.t1 < obj->dist)
    {
		obj->hit_point = v_add(ray->origin, v_scale(ray->direction, var.t1));
		if (in_cylinder_height(cylinder, obj->hit_point))
		{
			obj->dist = var.t1;
			obj->form = CYLINDER;
			return true;
		}
	}
	return false;
}

// Fonction pour vérifier l'intersection avec tous les cylindres
void hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit_objet *obj, int nb_cylinders)
{
    t_var_cylinder var;
    int i = 0;

    while (i < nb_cylinders)
    {
        // Initialisation des paramètres du cylindre
        var.oc = v_sub(ray->origin, cylinder[i].center);  // Vecteur du rayon au centre du cylindre
        var.axis_dot = v_dot(ray->direction, cylinder[i].axis);
        var.oc_dot = v_dot(var.oc, cylinder[i].axis);

        // Calcul des coefficients de l'équation quadratique
        var.a = v_dot(ray->direction, ray->direction) - var.axis_dot * var.axis_dot;
        var.b = 2.0 * (v_dot(ray->direction, var.oc) - var.axis_dot * var.oc_dot);
        var.c = v_dot(var.oc, var.oc) - var.oc_dot * var.oc_dot - (cylinder[i].diameter / 2.0) * (cylinder[i].diameter / 2.0);

        // Calcul du discriminant
        var.discriminant = var.b * var.b - 4.0 * var.a * var.c;

        // Si le discriminant est positif, il y a des intersections possibles
        if (var.discriminant >= 0)
        {
            if (assign_dist_cy(var, obj, cylinder[i], ray))  // On assigne la distance si une intersection est trouvée
				obj->index = i;
        }
        i++;
    }
}
