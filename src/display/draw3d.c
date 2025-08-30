/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:22:45 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 17:17:00 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

/**********************************************/
/*  Construction du rayon à travers un pixel  */
/**********************************************/
t_ray calculate_ray3d(int px, int py, t_camera cam)
{
    t_ray ray;
    const double aspect = (double)W_WIDTH / (double)W_HEIGHT;

    // Base caméra
    t_vec3 forward = v_norm(cam.orientation);
    t_vec3 world_up = vec3(0.0, 1.0, 0.0);
    t_vec3 right = v_norm(v_cross(forward, world_up));
    t_vec3 up    = v_norm(v_cross(right, forward));

    // Taille du plan image
    double half_height = tan(deg2rad(cam.fov) * 0.5);
    double half_width  = aspect * half_height;

    // Coordonnées pixel (NDC)
    double u = ( (px + 0.5) / (double)W_WIDTH ) * 2.0 - 1.0;
    double v = 1.0 - ( (py + 0.5) / (double)W_HEIGHT ) * 2.0;

    // Position sur le plan image
    double sx = u * half_width;
    double sy = v * half_height;

    ray.origin = cam.position;
    ray.direction = v_norm( v_add( v_add( v_scale(right, sx), v_scale(up, sy) ), forward ) );
    return ray;
}

/**********************************************/
/*  Intersections géométriques                */
/**********************************************/
static bool hit_sphere(const t_sphere *sp, const t_ray *r, double *out_t)
{
    t_vec3 oc = v_sub(r->origin, sp->center);
    double a = v_dot(r->direction, r->direction);
    double b = 2.0 * v_dot(oc, r->direction);
    double c = v_dot(oc, oc) - sp->radius * sp->radius;

    double disc = b*b - 4.0*a*c;
    if (disc < 0.0) return false;

    double sqrtD = sqrt(disc);
    double t1 = (-b - sqrtD) / (2.0*a);
    double t2 = (-b + sqrtD) / (2.0*a);

    const double eps = 1e-4;
    double t = (t1 > eps) ? t1 : ( (t2 > eps) ? t2 : -1.0 );
    if (t < 0.0) return false;

    *out_t = t;
    return true;
}

static bool hit_plane(const t_plane *pl, const t_ray *r, double *out_t)
{
    double denom = v_dot(pl->normal, r->direction);
    const double eps_parallel = 1e-6;
    if (fabs(denom) < eps_parallel) return false;

    double t = v_dot( v_sub(pl->point, r->origin), pl->normal ) / denom;
    const double eps = 1e-4;
    if (t <= eps) return false;

    *out_t = t;
    return true;
}

/**********************************************/
/*  Utilitaire : couleur                      */
/**********************************************/
static t_color color_scale(t_color c, double s)
{
    int r = fmin(255, c.r * s);
    int g = fmin(255, c.g * s);
    int b = fmin(255, c.b * s);
    return (t_color){r,g,b};
}

static t_color color_add(t_color a, t_color b)
{
    int rr = fmin(255, (int)a.r + (int)b.r);
    int gg = fmin(255, (int)a.g + (int)b.g);
    int bb = fmin(255, (int)a.b + (int)b.b);
    return (t_color){(unsigned char)rr, (unsigned char)gg, (unsigned char)bb};
}


/**********************************************/
/*  Shading avec Ambient + Light + Shadow     */
/**********************************************/
t_color ray_color3d(t_ray ray, t_scene scene)
{
    double t_sph, t_pl;
    bool hit_s = hit_sphere(scene.spheres, &ray, &t_sph);
    bool hit_p = hit_plane(scene.planes,  &ray, &t_pl);

    if (!hit_s && !hit_p)
        return (t_color){0, 0, 0}; // fond noir

    // On garde l'objet le plus proche
    double t;
    t_color base_color;
    t_vec3 hit_point;
    t_vec3 normal;

    if (hit_s && (!hit_p || t_sph < t_pl)) {
        t = t_sph;
        base_color = scene.spheres->color;
        hit_point = v_add(ray.origin, v_scale(ray.direction, t));
        normal = v_norm(v_sub(hit_point, scene.spheres->center));
    } else {
        t = t_pl;
        base_color = scene.planes->color;
        hit_point = v_add(ray.origin, v_scale(ray.direction, t));
        normal = v_norm(scene.planes->normal);
    }

    /* --- ÉTAPE 1 : lumière ambiante --- */
    t_color amb = color_scale(scene.ambient.color, scene.ambient.ratio);

    /* --- ÉTAPE 2 : calcul direction lumière --- */
    t_vec3 light_dir = v_norm(v_sub(scene.light.position, hit_point));

    /* --- ÉTAPE 3 : test d’ombre (shadow ray) --- */
    // On lance un rayon depuis hit_point vers la lumière
    t_ray shadow_ray;
    shadow_ray.origin = v_add(hit_point, v_scale(normal, 1e-4)); // petit offset pour éviter self-hit
    shadow_ray.direction = light_dir;

    bool in_shadow = false;
    double t_tmp;

    // Test intersection avec sphère
    if (hit_sphere(scene.spheres, &shadow_ray, &t_tmp)) {
        double dist_light = v_len(v_sub(scene.light.position, hit_point));
        if (t_tmp > 0.0 && t_tmp < dist_light)
            in_shadow = true;
    }
    // Test intersection avec plan
    if (hit_plane(scene.planes, &shadow_ray, &t_tmp)) {
        double dist_light = v_len(v_sub(scene.light.position, hit_point));
        if (t_tmp > 0.0 && t_tmp < dist_light)
            in_shadow = true;
    }

    /* --- ÉTAPE 4 : contribution diffuse (Lambert) --- */
    t_color diff_col = (t_color){0,0,0};
    if (!in_shadow) {
        double diff = fmax(0.0, v_dot(normal, light_dir));
        diff_col = color_scale(scene.light.color, scene.light.brightness * diff);
    }

    /* --- ÉTAPE 5 : composition finale --- */
    t_color light_contrib = color_add(amb, diff_col);

    t_color final;
    final.r = fmin(255, base_color.r * (light_contrib.r/255.0));
    final.g = fmin(255, base_color.g * (light_contrib.g/255.0));
    final.b = fmin(255, base_color.b * (light_contrib.b/255.0));

    return final;
}

/**********************************************/
/*  Rendering principal                       */
/**********************************************/
void put_pixel3d(t_mlx *data, int x, int y, int color)
{
    if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
        return;
    int offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
    *(unsigned int*)(data->addr + offset) = color;
}

void draw3d(t_mlx *data, t_scene scene)
{
    for (int y = 0; y < W_HEIGHT; y++)
    {
        for (int x = 0; x < W_WIDTH; x++)
        {
            t_ray ray = calculate_ray3d(x, y, scene.camera);
            t_color pixel_color = ray_color3d(ray, scene);

            int color = (pixel_color.r << 16) | (pixel_color.g << 8) | pixel_color.b;
            put_pixel3d(data, x, y, color);
        }
    }
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}

