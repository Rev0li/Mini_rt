/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:00:15 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/27 13:30:51 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/mini_rt.h"

static void	free_data(t_mlx *data)
{
	if (!data)
		return ;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	destroy_hook(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	mlx_loop_end(data->mlx);
	free_data(data);
	exit(0);
	return (0);
}