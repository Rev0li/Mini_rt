/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:33:36 by yafahfou          #+#    #+#             */
/*   Updated: 2025/10/21 16:33:44 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	parse_type_and_set(char *line, t_scene *scene, int i)
{
	if (line[i] == 'A' && line[i + 1] == ' ')
		return (set_ambient_ratio(line, scene, i));
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (set_camera(line, scene, i));
	else if (line[i] == 'L' && line[i + 1] == ' ')
		return (set_light(line, scene, i));
	else if (line[i] == 's' && line[i + 1] == 'p' && line[i + 2] == ' ')
		return (set_sphere(line, scene, i));
	else if (line[i] == 'p' && line[i + 1] == 'l' && line[i + 2] == ' ')
		return (set_plane(line, scene, i));
	else if (line[i] == 'c' && line[i + 1] == 'y' && line[i + 2] == ' ')
		return (set_cylinder(line, scene, i));
	printf("Not good object\n");
	return (-1);
}

int	parse_line(char *line, t_scene *scene)
{
	int	i;
	int	result;

	if (validate_line_chars(line) == -1)
		return (-1);
	i = 0;
	i = skip_whitespace(line, i);
	if (!line[i] || line[i] == '\n')
		return (0);
	result = parse_type_and_set(line, scene, i);
	if (result == -1)
		return (-1);
	return (result);
}

int	parse_file(char *file, t_scene *scene)
{
	char	*line;
	int		fd;

	if (get_data_from_file(file, scene) == -1)
		return (-1);
	if (safe_open(file, &fd) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, scene) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_scene_integrity(t_scene *scene)
{
	if (scene->has_ambient == false)
	{
		printf("Error: Please add ambient light\n");
		return (-1);
	}
	else if (scene->has_camera == false)
	{
		printf("Error: Please add camera\n");
		return (-1);
	}
	else if (scene->has_light == false)
	{
		printf("Error: Please add light\n");
		return (-1);
	}
	return (0);
}

int	check_file(char *file, t_scene *scene)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 3] == '.' && file[len - 2] == 'r' && file[len - 1] == 't')
	{
		if (parse_file(file, scene) == -1)
			return (-1);
		return (check_scene_integrity(scene));
	}
	else
	{
		printf("File is not good format\n");
		return (-1);
	}
}
