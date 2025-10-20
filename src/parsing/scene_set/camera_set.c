/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:37:52 by yafahfou          #+#    #+#             */
/*   Updated: 2025/10/20 19:35:01 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_camera(char *line, t_scene *scene, int index)
{
	int	fov;
	int	end;

	if (scene->has_camera)
		return (printf("Error: Duplicate camera definition\n"), -1);
	index = skip_whitespace(line, index + 1);
	if (parse_coordinates(line, &scene->camera.position, &index) == -1)
		return (-1);
	if (parse_normalized_vector(line, &scene->camera.orientation, &index) == -1)
		return (-1);
	index = skip_whitespace(line, index);
	if (!safe_atoi(line + index, &fov, &end))
		return (printf("Error: Invalid FOV value\n"), -1);
	if (!validate_fov(fov))
		return (-1);
	scene->camera.fov = fov;
	scene->has_camera = true;
	return (1);
}
