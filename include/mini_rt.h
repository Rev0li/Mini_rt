/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:08:33 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/20 15:03:12 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../lib/minilibx-linux/mlx.h"
#include "struct.h" 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// utils
void	*ft_calloc(size_t count, size_t size);

//tools_mlx
void	refresh_image(t_mlx *data);
int		key_hook(int keycode, t_mlx *data);
int		destroy_hook(void *param);

//display
void	draw(t_mlx *data);

