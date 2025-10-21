/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:08:33 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 12:58:01 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
#define MINI_RT_H
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// # include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx_macos/mlx.h"
//___________________________________________
// ◈◈◈◈◈◈◈◈ utils ◈◈◈◈◈◈◈◈
int is_part_of_number(char current, char next);
int is_valid_number_start(char current, char next);
int is_digit(char c);
int ft_strlen(const char *str);
void open_check(int fd);
void exit_error(char *message);
// ----- convert -----
double ft_atoi(const char *str);
// ----- get_line -----
char *get_next_line(int fd);
char *ft_strjoin_gnl(char const *s1, char const *s2, int index);
// ----- memory -----
void *ft_calloc(size_t nmemb, size_t size);
// ----- tools_mlx -----
bool init_app(t_mlx *data);
int key_hook(int keycode, t_mlx *data);
int mouse_hook(int keycode, int x, int y, t_mlx *data);
int destroy_hook(void *param);
//___________________________________________
// ◈◈◈◈◈◈◈◈ display ◈◈◈◈◈◈◈◈
t_hit_objet hit_object(t_ray ray, t_scene scene);
t_ray create_ray_from_pixel(int x, int y, t_camera *cam, t_mlx *data);
void put_pixel(t_mlx *data, int x, int y, unsigned int pixel_color);
int loop(t_mlx *data);
void draw(t_mlx *data);
// ----- light -----
unsigned int add_light(t_ray ray, t_scene scene, t_hit_objet obj);
t_vec3 get_normal(t_vec3 hit_point, t_hit_objet obj, t_scene scene);
bool is_in_shadow(t_vec3 hit_point, t_scene scene, t_vec3 light_dir, t_light light);
int clamp(float value, int min, int max);
t_vec3 get_light_direction(t_vec3 hit_point, t_light light);
float calculate_diffuse(t_vec3 normal, t_vec3 light_dir);

// ----- sphere -----
void hit_sphere(t_sphere *sphere,
				t_ray *ray, t_hit_objet *obj, int nb_spheres);
t_vec3 get_sphere_normal(t_vec3 hit_point, t_sphere *sphere);
// ----- plane -----
void hit_plane(t_plane *plane, t_ray *ray, t_hit_objet *obj, int nb_planes);
// ----- cylinder -----
// void	hit_cylinder(t_cylinder cylinder, t_ray *ray, float *dist);
//___________________________________________
// ◈◈◈◈◈◈◈◈ math ◈◈◈◈◈◈◈◈
t_vec3 set_vec(double x, double y, double z);
double v_len(t_vec3 a);
t_vec3 v_add(t_vec3 a, t_vec3 b);
t_vec3 v_sub(t_vec3 a, t_vec3 b);
t_vec3 v_scale(t_vec3 a, double s);
double v_dot(t_vec3 a, t_vec3 b);
t_vec3 v_cross(t_vec3 a, t_vec3 b);
double deg2rad(double d);
t_vec3 v_norm(t_vec3 a);
t_vec3 get_hit_point(t_ray ray, float distance);
double distance(t_vec3 a, t_vec3 b);
//___________________________________________
// ◈◈◈◈◈◈◈◈ Yass_Le_Bg ◈◈◈◈◈◈◈◈

int ft_index_line(char *s);
void ft_reset(char *s, int stop);

//___________________________________________
// ◈◈◈◈◈◈◈◈ parsing ◈◈◈◈◈◈◈◈
int set_cylinder(char *line, t_scene *scene, int index);
int set_cy_normal(t_scene *scene, char *line, int pos);
int set_cy_center(t_scene *scene, char *line, int pos);

int set_plane(char *line, t_scene *scene, int index);
int set_sphere(char *line, t_scene *scene, int index);
int set_light(char *line, t_scene *scene, int index);
// ----- verification -----
// check_file.c
int check_file(char *file, t_scene *scene);
int parse_file(char *file, t_scene *scene);
int parse_line(char *line, t_scene *scene);
// get_set_data.c
void get_data_from_file(char *file, t_scene *scene);

// ambiant_set.c
int set_ambient_ratio(char *line, t_scene *scene, int index);

// color_set.c
int set_color(t_color *color, int n, int choose);
int parse_color(char *line, t_color *color, int index);

// camera_set.c
void set_camera_pos(t_camera *camera, char *line, int pos);
int set_orientation_values(t_camera *camera, char *line, int pos);
int set_fov_value(t_scene *scene, char *line, int index);
int set_cam_orientation(t_scene *scene, char *line, int index);
int set_camera(char *line, t_scene *scene, int index);

void hit_cylinder(t_cylinder *cylinders, t_ray *ray, t_hit_objet *object, int nb_cylinders);
t_vec3 get_cylinder_normal(t_vec3 hit_point, t_cylinder *cylinder);
void hit_circle(t_cylinder *cylindre, t_ray *ray, t_hit_objet *obj, int nb_cylinders);

//_____________________A SUPRIMER_________________
// ◈◈◈◈◈◈◈◈ debug ◈◈◈◈◈◈◈◈
void print_data(t_scene *scene);
t_color return_color(t_hit_objet obj, t_scene scene);
unsigned int return_color_hex(t_hit_objet obj, t_scene scene);
#endif
