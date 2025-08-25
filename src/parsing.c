/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:37:52 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/25 12:22:41 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

int set_color(t_color *color, int n, int choose)
{
	if (n < 0 || n > 255)
		return (-1);
	if (choose == 1)
		color->r = n;
	else if (choose == 2)
		color->g = n;
	else
		color->b = n;
	return (1);
}

int parse_color(char *line, t_color *color, int index)
{
	int i;
	int option;

	option = 1;
	i = index;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]))
				i++;
			if (set_color(color, ft_atoi(line + index), option) == -1)
				return (-1);
			option++;
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
