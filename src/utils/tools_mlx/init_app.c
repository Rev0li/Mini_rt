/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:00:58 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 16:22:45 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/mini_rt.h"

static bool	init_img(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img)
	{
		printf("Fail mlx_new_image function\n");
		return (false);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
	{
		printf("Fail mlx_get_data_addr function\n");
		return (false);
	}
	return (true);
}

bool	init_app(t_mlx *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Fail mlx_init function\n");
		return (false);
	}
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT,
			"Mini_RT");
	if (!data->window)
	{
		printf("Fail mlx_new_window function\n");
		return (false);
	}
	if (!init_img(data))
		return (false);
	return (true);
}
