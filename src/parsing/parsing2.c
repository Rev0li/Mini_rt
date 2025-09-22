/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:40:43 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/25 19:57:42 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

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

int set_ambient_ratio(char *line, t_scene *scene, int index)
{
	size_t i;

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
			return (parse_color(line, &scene->ambient.color, index));
		}
		else
			index++;
	}
	return (1);
}

void alloc_data(t_scene *scene)
{
	if (scene->nb_spheres != 0)
		scene->spheres = ft_calloc(scene->nb_spheres, sizeof(t_sphere));
	if (!scene->spheres && scene->nb_spheres != 0)
		exit(EXIT_FAILURE);
	if (scene->nb_cylinders != 0)
	{
		scene->cylinders = ft_calloc(scene->nb_cylinders, sizeof(t_cylinder));
		if (!scene->cylinders)
		{
			free(scene->spheres);
			exit(EXIT_FAILURE);
		}
	}
	if (scene->nb_planes != 0)
	{
		scene->planes = ft_calloc(scene->nb_planes, sizeof(t_plane));
		if (!scene->planes)
		{
			free(scene->spheres);
			free(scene->cylinders);
			exit(EXIT_FAILURE);
		}
	}
}

void set_data(char *line, t_scene *scene)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 's' && line[i + 1] == 'p')
			scene->nb_spheres++;
		else if (line[i] == 'c' && line[i + 1] == 'y')
			scene->nb_cylinders++;
		else if (line[i] == 'p' && line[i + 1] == 'l')
			scene->nb_planes++;
		i++;
	}
}

void get_data_from_file(char *file, t_scene *scene)
{
	char *line;
	int fd;

	fd = open(file, O_RDONLY);
	open_check(fd);
	line = get_next_line(fd);
	while (line)
	{
		set_data(line, scene);
		line = get_next_line(fd);
	}
	alloc_data(scene);
	close(fd);
}
