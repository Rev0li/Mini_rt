/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:40:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/30 15:40:29 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

void	free_scene_objects(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->spheres)
	{
		free(scene->spheres);
		scene->spheres = NULL;
	}
	if (scene->planes)
	{
		free(scene->planes);
		scene->planes = NULL;
	}
	if (scene->cylinders)
	{
		free(scene->cylinders);
		scene->cylinders = NULL;
	}
}

void	free_mlx_resources(t_mlx *data)
{
	if (!data)
		return ;
	if (data->img && data->mlx)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->window && data->mlx)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_all(t_mlx *data)
{
	if (!data)
		return ;
	free_scene_objects(&data->scene);
	free_mlx_resources(data);
	free(data);
}

void	exit_free(t_mlx *data)
{
	free_all(data);
	exit(EXIT_FAILURE);
}
