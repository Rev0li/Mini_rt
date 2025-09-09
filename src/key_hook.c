/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:02:20 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/26 11:02:31 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void refresh_image(t_mlx *data)
{
    mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}

int	key_hook(int keycode, t_mlx *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
		destroy_hook(data);
	else if (keycode == 114)
		refresh_image(data);
	return (0);
}