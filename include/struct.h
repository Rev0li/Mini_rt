/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:52:42 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 14:55:17 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H


# define W_HEIGHT 1080
# define W_WIDTH 1920

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>



// Structure pour les vecteurs 3D et coordonnées
typedef struct s_vec3
{
    double x;
    double y;
    double z;
} t_vec3;

// Structure pour les couleurs
typedef struct s_color
{
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
} t_color;

// Rayon (origine + direction)
typedef struct s_ray
{
    t_vec3 origin;
    t_vec3 direction;
} t_ray;

// Structure pour l'éclairage ambiant (A)
typedef struct s_ambient
{
    double ratio;        // [0.0, 1.0]
    t_color color;       // RGB [0-255]
} t_ambient;

// Structure pour la caméra (C)
typedef struct s_camera
{
    t_vec3 position;     // coordonnées x,y,z
    t_vec3 orientation;  // vecteur normalisé [-1,1]
    double fov;          // [0, 180]
} t_camera;

// Structure pour la lumière (L)
typedef struct s_light
{
    t_vec3 position;     // coordonnées x,y,z
    double brightness;   // [0.0, 1.0]
    t_color color;       // RGB [0-255]
} t_light;

// Structure pour la sphère (sp)
typedef struct s_sphere
{
    t_vec3 center;       // coordonnées x,y,z
    double radius;     // > 0
    t_color color;       // RGB [0-255]
} t_sphere;

// Structure pour le plan (pl)
typedef struct s_plane
{
    t_vec3 point;        // un point sur le plan
    t_vec3 normal;       // vecteur normal normalisé [-1,1]
    t_color color;       // RGB [0-255]
} t_plane;

// Structure pour le cylindre (cy)
typedef struct s_cylinder
{
    t_vec3 center;       // coordonnées x,y,z
    t_vec3 axis;         // vecteur d'axe normalisé [-1,1]
    double diameter;     // > 0
    double height;       // > 0
    t_color color;       // RGB [0-255]
} t_cylinder;


typedef struct s_scene
{
    t_camera camera;
    t_sphere sphere;
    t_plane plane;
    t_ambient ambient;  // lumière ambiante
    t_light light;      // lumière ponctuelle
} t_scene;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_scene	scene;
}	t_mlx;

/*// Structure principale de la scène*/
/*typedef struct s_scene*/
/*{*/
/*    // Éléments uniques (définis par une majuscule)*/
/*    t_ambient ambient;      // A - obligatoire*/
/*    t_camera camera;        // C - obligatoire*/
/**/
/*    t_light light;        // tableau dynamique*/
/*    int nb_lights;*/
/**/
/*    // Objets (peut y en avoir plusieurs)*/
/*    t_sphere *spheres;      // tableau dynamique*/
/*    int nb_spheres;*/
/**/
/*    t_plane *planes;        // tableau dynamique*/
/*    int nb_planes;*/
/**/
/*    t_cylinder *cylinders;  // tableau dynamique*/
/*    int nb_cylinders;*/
/**/
/*    // Flags pour vérifier que les éléments obligatoires sont présents*/
/*    bool    has_ambient;*/
/*    bool    has_camera;*/
/*    bool    has_light;*/
/*} t_scene;*/

#endif
