/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:38:53 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/30 11:38:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

int	loop(t_mlx *data)
{
		if (init_app(data))
		{
			/*draw(data, data->scene);*/
			draw3d(data, data->scene);
			mlx_hook(data->window, 2, 1L << 0, key_hook, data);
			mlx_hook(data->window, 4, 1L << 2, mouse_hook, data);
			mlx_loop(data->mlx);
		}
		else
		{
			printf("Fail init app\n");
			return (1);
		}
	return (0);
}
