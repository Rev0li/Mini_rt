/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:08:33 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 17:55:17 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "struct.h" 
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "../lib/minilibx-linux/mlx.h"
// ◈◈◈◈◈◈◈◈ parsing ◈◈◈◈◈◈◈◈
// ----- check_file -----
int				check_file(char *file, t_scene *scene);
// ◈ utils ◈
// ----- get_set_data.c ----- 
int				get_data_from_file(char *file, t_scene *scene);
// ----- validate_line_chars ------
int				validate_line_chars(char *line);
int				is_valid_number_start(char c, char next);
int				is_valid_char(char c);
// ----- scene_set -----
int				set_cylinder(char *line, t_scene *scene, int index);
int				set_plane(char *line, t_scene *scene, int index);
int				set_sphere(char *line, t_scene *scene, int index);
int				set_light(char *line, t_scene *scene, int index);
// ----- Valid_range -----
int				validate_normalized(double value);
int				validate_fov(int value);
int				validate_positive(double value);
int				validate_ratio(double value);
//----- parse_coordinates -----
int				parse_coordinates(char *line, t_vec3 *vec, int *idx);
int				parse_normalized_vector(char *line, t_vec3 *vec, int *idx);
// ----- scene_set -----
int				set_ambient_ratio(char *line, t_scene *scene, int index);
int				set_camera(char *line, t_scene *scene, int index);
int				set_color(t_color *color, int n, int choose);
int				parse_color(char *line, t_color *color, int index);
//___________________________________________
// ◈◈◈◈◈◈◈◈ utils ◈◈◈◈◈◈◈◈
///////
int				safe_atof(char *str, double *result, int *end_index);
int				safe_atoi(char *str, int *result, int *end_index);
double			ft_atoi(const char *str);
int				ft_is_digit(char c);
int				ft_strlen(const char *str);
void			exit_free(t_mlx *data);
void			free_all(t_mlx *data);
int				safe_open(char *file, int *fd);
int				skip_whitespace(char *line, int index);
int				ft_isspace(char c);
int				expect_comma(char *line, int *index);
t_color			return_color(t_hit_objet obj, t_scene scene);
unsigned int	return_color_hex(t_hit_objet obj, t_scene scene);
// ----- get_line -----
char			*get_next_line(int fd);
char			*ft_strjoin_gnl(char const *s1, char const *s2, int index);
// ----- memory -----
void			*ft_calloc(size_t nmemb, size_t size);
// ----- tools_mlx -----
bool			init_app(t_mlx *data);
int				key_hook(int keycode, t_mlx *data);
int				mouse_hook(int keycode, int x, int y, t_mlx *data);
int				destroy_hook(void *param);
//___________________________________________
// ◈◈◈◈◈◈◈◈ display ◈◈◈◈◈◈◈◈
t_hit_objet		hit_object(t_ray ray, t_scene scene);
t_ray			create_ray_from_pixel(int x, int y, t_camera *cam, t_mlx *data);
void			put_pixel(t_mlx *data, int x, int y, unsigned int pixel_color);
int				loop(t_mlx *data);
void			draw(t_mlx	*data);
// ----- light -----
unsigned int	add_light(t_ray ray, t_scene scene, t_hit_objet obj);
t_vec3			get_normal(t_vec3 hit_point, t_hit_objet obj, t_scene scene);
bool			is_in_shadow(t_vec3 hit_point, t_scene scene,
					t_vec3 light_dir, t_light light);
int				clamp(float value, int min, int max);
t_vec3			get_light_direction(t_vec3 hit_point, t_light light);
float			calculate_diffuse(t_vec3 normal, t_vec3 light_dir);

// ----- sphere -----
void			hit_sphere(t_sphere *sphere,
					t_ray *ray, t_hit_objet *obj, int nb_spheres);
t_vec3			get_sphere_normal(t_vec3 hit_point, t_sphere *sphere);
// ----- plane -----
void			hit_plane(t_plane *plane, t_ray *ray,
					t_hit_objet *obj, int nb_planes);
// ----- cylinder -----
void			hit_cylinder(t_cylinder *cylinder, t_ray *ray,
					t_hit_objet *obj, int nb_cylinders);
t_vec3			get_cylinder_normal(t_vec3 hit_point, t_cylinder *sphere);
void			hit_circle(t_cylinder *cylindre, t_ray *ray,
					t_hit_objet *obj, int nb_cylinders);
//___________________________________________
// ◈◈◈◈◈◈◈◈ math ◈◈◈◈◈◈◈◈
t_vec3			set_vec(double x, double y, double z);
double			v_len(t_vec3 a);
t_vec3			v_add(t_vec3 a, t_vec3 b);
t_vec3			v_sub(t_vec3 a, t_vec3 b);
t_vec3			v_scale(t_vec3 a, double s);
double			v_dot(t_vec3 a, t_vec3 b);
t_vec3			v_cross(t_vec3 a, t_vec3 b);
double			deg2rad(double d);
t_vec3			v_norm(t_vec3 a);
t_vec3			get_hit_point(t_ray ray, float distance);
double			distance(t_vec3 a, t_vec3 b);
//___________________________________________
// ◈◈◈◈◈◈◈◈ Yass_Le_Bg ◈◈◈◈◈◈◈◈
int				ft_index_line(char *s);
void			ft_reset(char *s, int stop);
//___________________________________________
//_____________________A SUPRIMER_________________
// ◈◈◈◈◈◈◈◈ debug ◈◈◈◈◈◈◈◈
void	print_data(t_scene *scene);

#endif
