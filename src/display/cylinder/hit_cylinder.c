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

void	hit_cylinder(t_cylinder cylinder,t_ray *ray, t_hit_objet *object, int nb_cylinders)
{
    double  a;
    double  b;
    double  c;
    double  t[2];
    int     i;
    float   discriminant;
    float   z1;
	float	z2;

    i = 0;
    while (i < nb_cylinders)
    {
        a = (ray->direction.x * ray->direction.x) + (ray->direction.y * ray->direction.y);
        b = 2 * ((ray->origin.x * ray->direction.x) + (ray->origin.y * ray->direction.y));
        c = ((ray->origin.x * ray->origin.x) + (ray->origin.y * ray->origin.y) -1);
        discriminant = (b * b) - (4 * a * c);
        if (discriminant > 0)
        {
            t[0] = (-b + sqrt(discriminant)) / (2*a);
            t[1] = (-b - sqrt(discriminant)) / (2*a);
			z1 = ray->origin.z + (t[0] * ray->direction.z);
			if (-1 <= z1 && z1 >= 1)
			{
				object->dist = t[0];
				object->index = i;
				object->form = CYLINDRE;
			}
			z2 = ray->origin.z + (t[1] * ray->direction.z);
        }
        if (discriminant < 0)
        {
            i++;
            continue;
        }
        
		
    } 
}

