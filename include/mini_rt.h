/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:08:33 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/30 15:49:01 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/minilibx-linux/mlx.h"

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


// ◈◈◈◈◈◈◈◈ utils ◈◈◈◈◈◈◈◈
int		is_digit(char c);
int		ft_strlen(const char *str);
// ----- convert -----
double	ft_atoi(const char *str);
// ----- get_line -----
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2, int index);
// ----- memory -----
void	*ft_calloc(size_t nmemb, size_t size);
// ----- tools_mlx -----
bool	init_app(t_mlx *data);
void	refresh_image(t_mlx *data);
int		key_hook(int keycode, t_mlx *data);
int		mouse_hook(int	keycode,int x, int y, t_mlx *data);
int		destroy_hook(void *param);
//___________________________________________
// ◈◈◈◈◈◈◈◈ display ◈◈◈◈◈◈◈◈
int		loop(t_mlx *data);
void	draw(t_mlx *data, t_scene scene);
void	draw3d(t_mlx *data, t_scene scene);
//___________________________________________
// ◈◈◈◈◈◈◈◈ math ◈◈◈◈◈◈◈◈
t_vec3	vec3(double x, double y, double z);
double	v_len(t_vec3 a);
t_vec3	v_add(t_vec3 a, t_vec3 b);
t_vec3	v_sub(t_vec3 a, t_vec3 b);
t_vec3	v_scale(t_vec3 a, double s);
double	v_dot(t_vec3 a, t_vec3 b);
t_vec3	v_cross(t_vec3 a, t_vec3 b);
double	deg2rad(double d);
t_vec3	v_norm(t_vec3 a);
//___________________________________________

// ◈◈◈◈◈◈◈◈ Yass_Le_Bg ◈◈◈◈◈◈◈◈

int		ft_index_line(char *s);
void	ft_reset(char *s, int stop);
int		set_color(t_color *color, int n, int choose);
int		parse_color(char *line, t_color *color, int index);
void	set_camera_pos(t_camera *camera, char *line, int pos);
int		set_orientation_values(t_camera *camera, char *line, int pos);
int		set_fov_value(t_scene *scene, char *line, int index);
int		check_file(char *file, t_scene *scene);
int		parse_file(char *file, t_scene *scene);
int		parse_line(char *line, t_scene *scene);
int		set_cam_orientation(t_scene *scene, char *line, int index);
int		set_camera(char *line, t_scene *scene, int index);
int		set_cylinder(char *line, t_scene *scene, int index);
int		set_plane(char *line, t_scene *scene, int index);
int		set_sphere(char *line, t_scene *scene, int index);
int		set_light(char *line, t_scene *scene, int index);
void	open_check(int fd);
void	exit_error(char *message);
int		set_ambient_ratio(char *line, t_scene *scene, int index);
void	get_data_from_file(char *file, t_scene *scene);

#endif
