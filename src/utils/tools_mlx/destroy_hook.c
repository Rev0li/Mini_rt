/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:15:06 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/09 17:48:48 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

static void free_data(t_mlx *data)
{
	if (!data)
		return;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		// mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int destroy_hook(void *param)
{
	t_mlx *data;

	// data = (t_mlx *)param;
	(void)param;
	(void)data;
	data = NULL;
	// mlx_loop_end(data->mlx);
	free_data(data);
	exit(0);
	return (0);
}
