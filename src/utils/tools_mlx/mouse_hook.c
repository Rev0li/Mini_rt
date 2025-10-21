/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:37:07 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/29 18:21:07 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	mouse_hook(int keycode, int x, int y, t_mlx *data)
{
	(void)x;
	(void)y;
	printf("Mouse keycode : %d\n", keycode);
	if (keycode == 5)
	{
		data->scene.camera.fov += 1;
	}
	else if (keycode == 4)
	{
		data->scene.camera.fov -= 1;
	}
	draw(data);
	return (0);
}
