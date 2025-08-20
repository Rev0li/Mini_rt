/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:46:13 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/20 14:26:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/mini_rt.h"

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
