/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:04 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/20 16:35:09 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	open_check(int fd)
{
	if (fd == -1)
	{
		write(2, "Error open\n", 11);
		exit(EXIT_FAILURE);
	}
}

void	exit_error(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	set_color(t_color *color, int n, int choose)
{
	if (n < 0 || n > 255)
		return (-1);
	if (choose == 0)
		color->r = n;
	else if (choose == 1)
		color->g = n;
	else
		color->b = n;
	return (1);
}

int	set_ambient_color(char *line, t_scene *scene, int index)
{
	int	i;
	int	color;

	color = 0;
	i = index;
	// printf("line: %s\n", line + index);
	// printf("index: %d\n", index);
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]))
				i++;
			if (set_color(&scene->ambient.color, ft_atoi(line + index), color) == -1)
				return (-1);
			color++;
			index = i;
		}
		else
			index++;
	}
	return (1);
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

int	set_camera(char *line, t_scene *scene, int index)
{
	(void)line;
	(void)scene;
	index = 0;
	return (1);
}

int	set_light(char *line, t_scene *scene, int index)
{
	(void)line;
	(void)scene;
	index = 0;
	return (1);
}

int set_sphere(char *line, t_scene *scene, int index)
{
	(void)line;
	(void)scene;
	index = 0;
	return (1);
}
int set_plane(char *line, t_scene *scene, int index)
{
	(void)line;
	(void)scene;
	index = 0;
	return (1);
}

int set_cylinder(char *line, t_scene *scene, int index)
{
	(void)line;
	(void)scene;
	index = 0;
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
				return (set_camera(line, scene, i));
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

int main(int ac, char **av)
{
	t_scene	scene;

	scene.has_ambient = false;
	scene.has_camera = false;
	scene.has_light = false;
	if (ac == 2)
	{
		if (check_file(av[1], &scene) == -1)
			write(2, "Error\n", 6);
	}
	else
		printf("error argument\n");
	printf("ratio %f\n", scene.ambient.ratio);
	printf("colors: %d, %d, %d\n", scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
}
