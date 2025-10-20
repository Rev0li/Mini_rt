/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:33:36 by yafahfou          #+#    #+#             */
/*   Updated: 2025/10/20 20:10:23 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	check_file(char *file, t_scene *scene)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 3] == '.' && file[len - 2] == 'r' && file[len - 1] == 't')
	{
		if (parse_file(file, scene) == -1)
			return (-1);
		return (0);
	}
	else
	{
		printf("File is not good format\n");
		return (-1);
	}
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

int	parse_type_and_set(char *line, t_scene *scene, int i)
{
	if (line[i] == 'A' && line[i + 1] == ' ')
		return (set_ambient_ratio(line, scene, i));
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (set_camera(line, scene, i));
	else if (line[i] == 'L' && line[i + 1] == ' ')
		return (set_light(line, scene, i));
	else if (line[i] == 's' && line[i + 1] == 'p')
		return (set_sphere(line, scene, i));
	else if (line[i] == 'p' && line[i + 1] == 'l')
		return (set_plane(line, scene, i));
	else if (line[i] == 'c' && line[i + 1] == 'y')
		return (set_cylinder(line, scene, i));
	printf("Not good object\n");
	return (-1);
}

int	is_valid_identifier_char(char c)
{
	return (c == 'A' || c == 'C' || c == 'L' || c == 's' 
		|| c == 'p' || c == 'c' || c == 'y' || c == 'l');
}

int	validate_line_chars(char *line)
{
	int	i;

	i = 0;
	// Skip les lignes vides
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	// Vérifie les identifiants en début de ligne
	while (line[i] && is_valid_identifier_char(line[i]))
		i++;
	// Vérifie le reste de la ligne
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_char(line[i]))
		{
			printf("Error: Invalid character '%c' at position %d\n", 
				line[i], i);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	parse_line(char *line, t_scene *scene)
{
	int	i;
	int	result;

	if (validate_line_chars(line) == -1)
		return (-1);
	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
		{
			result = parse_type_and_set(line, scene, i);
			if (result == -1)
				return (-1);
			if (result != 0)
				return (result);
		}
		i++;
	}
	return (1);
}
