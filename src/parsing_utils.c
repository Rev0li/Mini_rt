/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:33:36 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/21 14:26:39 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

int	check_file(char *file, t_scene *scene)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 3] == '.' && file[len - 2] == 'r' && file[len - 1] == 't')
	{
		if (parse_file(file, scene) == -1)
			return(-1);
		else
			return (1);
	}
	else
		return (-1);
}

int	parse_file(char *file, t_scene *scene)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	open_check(fd);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, scene) == -1)
			return (-1);
		line = get_next_line(fd);	
	}
	return (1);
}

int	parse_line(char *line, t_scene *scene)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		// printf("here\n");
		if (line[i] == 'A')
		{
			if (scene->has_ambient == true)
				return (-1);
			else
				return (set_ambient_ratio(line, scene, i));
		}
		else if (line[i] == 'C')
		{
			if (scene->has_camera == true)
				return (-1);
			else
			{
				// printf("ici\n");
				return (set_camera(line, scene, i));
			}
		}
		else if (line[i] == 'L')
		{
			if (scene->has_light == true)
				return (-1);
			else
				return (set_light(line, scene, i));
		}
		else if (line[i] == 's' && line[i + 1] == 'p')
			return (set_sphere(line, scene, i));
		else if (line[i] == 'p' && line[i + 1] == 'l')
			return (set_plane(line, scene, i));
		else if (line[i] == 'c' && line[i + 1] == 'y')
			return (set_cylinder(line, scene, i));
		else if (line[i] && line[i] != ' ' && line[i] != '\n')
		{
			printf("line[i]: %c\n", line[i + 6]);
			exit_error("Error parsing file\n");
		}
		i++;		
	}
	return (1);
}
