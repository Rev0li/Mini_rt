/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:08:33 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 14:08:05 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "struct.h" 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

# define M_PI 3.14159265358979323846

// utils
void	*ft_calloc(size_t count, size_t size);

//tools_mlx
bool	init_app(t_mlx *data);
void	refresh_image(t_mlx *data);
int		key_hook(int keycode, t_mlx *data);
int		mouse_hook(int	keycode,int x, int y, t_mlx *data);
int		destroy_hook(void *param);

//display

void	draw(t_mlx *data, t_scene scene);
void	draw3d(t_mlx *data, t_scene scene);

// math
t_vec3	vec3(double x, double y, double z);
double	v_len(t_vec3 a);
t_vec3	v_add(t_vec3 a, t_vec3 b);
t_vec3	v_sub(t_vec3 a, t_vec3 b);
t_vec3	v_scale(t_vec3 a, double s);
double	v_dot(t_vec3 a, t_vec3 b);
t_vec3	v_cross(t_vec3 a, t_vec3 b);
double	deg2rad(double d);
t_vec3	v_norm(t_vec3 a);

