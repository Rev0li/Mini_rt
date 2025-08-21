/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:40:43 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/21 14:24:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

int	set_cam_orientation(t_scene *scene, char *line, int index)
{
	int	i;
	int	pos;

	i = index;
	pos = 1;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			if (pos == 4)
				return (set_fov_value(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			set_orientation_values(&scene->camera, line + index, pos);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (1);
}

int	set_camera(char *line, t_scene *scene, int index)
{
	int	i;
	int	pos;

	i = index;
	pos = 1;
	scene->has_camera = true;
	printf("line: %s\bn", line);
	// printf("index: %d\n", index);
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			if (pos == 4)
				return (set_cam_orientation(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			set_camera_pos(&scene->camera, line + index, pos);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (-1);
}

int	set_ambient_ratio(char *line, t_scene *scene, int index)
{
	size_t	i;

	i = index;
	scene->has_ambient = true;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			scene->ambient.ratio = ft_atoi(line + index);
			if (0.0 > scene->ambient.ratio || scene->ambient.ratio > 1.0)
				return (-1);
			index = i;
			// printf("index: %d\n", index);
			return (set_ambient_color(line, scene, index));
		}
		else
			index++;
	}
	return (1);
}
