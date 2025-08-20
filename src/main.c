/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:48:31 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/20 14:27:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/mini_rt.h"


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

static bool	init_app(t_mlx *data)
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

int	main  (int argc, char **argv)
{
	t_mlx	*data;

	data = NULL;
	if (argc == 2)
	{
		printf("%s\n", argv[1]);// check argv[1] before parse
		// if file or contained is not good return (1)
		data = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
		if (init_app(data))
		{
			draw(data);
			mlx_hook(data->window, 2, 1L << 0, key_hook, data);
			mlx_hook(data->window, 17, 0, destroy_hook, data);
			mlx_loop(data->mlx);
		}
		else
		{
			printf("Fail init app\n");
			return (1);
		}
	}
	printf("Usage: ./miniRT MAP_FILE.rt\n");
	return (1);
}
