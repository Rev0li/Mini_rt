/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:01:50 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/22 16:00:29 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
#define MINI_RT_H

#define W_HEIGHT 1000
#define W_WIDTH 1000

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_mlx
{
    void *mlx;
    void *window;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_mlx;

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
    unsigned char r;
    unsigned char g;
    unsigned char b;
} t_color;

// Structure pour l'éclairage ambiant (A)
typedef struct s_ambient
{
    double ratio;  // [0.0, 1.0]
    t_color color; // RGB [0-255]
} t_ambient;

// Structure pour la caméra (C)
typedef struct s_camera
{
    t_vec3 position;    // coordonnées x,y,z
    t_vec3 orientation; // vecteur normalisé [-1,1]
    double fov;         // [0, 180]
} t_camera;

// Structure pour la lumière (L)
typedef struct s_light
{
    t_vec3 position;   // coordonnées x,y,z
    double brightness; // [0.0, 1.0]
    t_color color;     // RGB [0-255]
} t_light;

// Structure pour la sphère (sp)
typedef struct s_sphere
{
    t_vec3 center;   // coordonnées x,y,z
    double diameter; // > 0
    t_color color;   // RGB [0-255]
} t_sphere;

// Structure pour le plan (pl)
typedef struct s_plane
{
    t_vec3 point;  // un point sur le plan
    t_vec3 normal; // vecteur normal normalisé [-1,1]
    t_color color; // RGB [0-255]
} t_plane;

// Structure pour le cylindre (cy)
typedef struct s_cylinder
{
    t_vec3 center;   // coordonnées x,y,z
    t_vec3 axis;     // vecteur d'axe normalisé [-1,1]
    double diameter; // > 0
    double height;   // > 0
    t_color color;   // RGB [0-255]
} t_cylinder;

// Structure principale de la scène
typedef struct s_scene
{
    // Éléments uniques (définis par une majuscule)
    t_ambient ambient; // A - obligatoire
    t_camera camera;   // C - obligatoire

    t_light light; // tableau dynamique
    int nb_lights;

    // Objets (peut y en avoir plusieurs)
    t_sphere *spheres; // tableau dynamique
    int nb_spheres;
    int sphere_index;

    t_plane *planes; // tableau dynamique
    int nb_planes;
    int plane_index;

    t_cylinder *cylinders; // tableau dynamique
    int nb_cylinders;
    int cylinder_index;

    // Flags pour vérifier que les éléments obligatoires sont présents
    bool has_ambient;
    bool has_camera;
    bool has_light;
} t_scene;

char *get_next_line(int fd);
char *ft_strjoin_gnl(char const *s1, char const *s2, int index);
int ft_index_line(char *s);
void ft_reset(char *s, int stop);
double ft_atoi(const char *str);
int is_digit(char c);
int ft_strlen(const char *str);
int set_color(t_color *color, int n, int choose);
int parse_color(char *line, t_color *color, int index);
void set_camera_pos(t_camera *camera, char *line, int pos);
int set_orientation_values(t_camera *camera, char *line, int pos);
int set_fov_value(t_scene *scene, char *line, int index);
int check_file(char *file, t_scene *scene);
int parse_file(char *file, t_scene *scene);
int parse_line(char *line, t_scene *scene);
int set_cam_orientation(t_scene *scene, char *line, int index);
int set_camera(char *line, t_scene *scene, int index);
int set_cylinder(char *line, t_scene *scene, int index);
int set_plane(char *line, t_scene *scene, int index);
int set_sphere(char *line, t_scene *scene, int index);
int set_light(char *line, t_scene *scene, int index);
void open_check(int fd);
void exit_error(char *message);
int set_ambient_ratio(char *line, t_scene *scene, int index);
void get_data_from_file(char *file, t_scene *scene);
void *ft_calloc(size_t nmemb, size_t size);

#endif