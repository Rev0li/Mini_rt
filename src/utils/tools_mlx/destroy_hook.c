/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:15:06 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/19 14:19:10 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/mini_rt.h"

int	key_hook(int keycode, t_mlx *data)
{
	if (keycode == 65307)
		destroy_hook(data);
	return (0);
}

int	destroy_hook(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	mlx_loop_end(data->mlx);
	/*close_app(data, false, true);*/
	exit(0);
	return (0);
}
