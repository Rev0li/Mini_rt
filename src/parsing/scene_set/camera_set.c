/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:37:52 by yafahfou          #+#    #+#             */
/*   Updated: 2025/09/24 12:02:44 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int set_camera(char *line, t_scene *scene, int index)
{
	int i;
	int pos;

	i = index;
	pos = 1;
	scene->has_camera = true;
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

int set_cam_orientation(t_scene *scene, char *line, int index)
{
	int i;
	int pos;

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

void set_camera_pos(t_camera *camera, char *line, int pos)
{
	if (pos == 1)
		camera->position.x = ft_atoi(line);
	else if (pos == 2)
		camera->position.y = ft_atoi(line);
	else
		camera->position.z = ft_atoi(line);
}

int set_orientation_values(t_camera *camera, char *line, int pos)
{

	if (pos == 1)
	{
		camera->orientation.x = ft_atoi(line);
		if (camera->orientation.x < -1 || camera->orientation.x > 1)
			return (-1);
	}
	else if (pos == 2)
	{
		camera->orientation.y = ft_atoi(line);
		if (camera->orientation.y < -1 || camera->orientation.y > 1)
			return (-1);
	}
	else
	{
		camera->orientation.z = ft_atoi(line);
		if (camera->orientation.z < -1 || camera->orientation.z > 1)
			return (-1);
	}
	return (1);
}

int set_fov_value(t_scene *scene, char *line, int index)
{
	scene->camera.fov = ft_atoi(line + index);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		return (-1);
	return (1);
}
