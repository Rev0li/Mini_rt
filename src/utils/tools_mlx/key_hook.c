/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:46:13 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/29 18:23:10 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	key_hook(int keycode, t_mlx *data)
{
	if (keycode == 65453)
		data->scene.ambient.ratio -= 0.05;
	else if (keycode == 65451)
		data->scene.ambient.ratio += 0.05;
	else if (keycode == 119)
		data->scene.camera.position.z -= 0.1;
	else if (keycode == 115)
		data->scene.camera.position.z += 0.1;
	else if (keycode == 97)
		data->scene.camera.orientation.x -= 0.01;
	else if (keycode == 100)
		data->scene.camera.orientation.x += 0.01;
	else if (keycode == 101)
		data->scene.camera.position.y += 0.1;
	else if (keycode == 113)
		data->scene.camera.position.y -= 0.1;
	else if (keycode == 65307)
		destroy_hook(data);
	draw(data);
	return (0);
}
