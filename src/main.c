/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:04 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/21 14:52:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void	set_light_pos(t_light *light, char *line, int pos)
{
	if (pos == 1)
		light->position.x = ft_atoi(line);
	if (pos == 2)
		light->position.y = ft_atoi(line);
	else
		light->position.z = ft_atoi(line);
}

int	set_light_brightness(t_scene *scene, char *line, int index)
{
	scene->light.brightness = ft_atoi(line + index);
	if (scene->light.brightness < 0 || scene->light.brightness > 1)
		return (-1);
	return (1);
}

int	set_light(char *line, t_scene *scene, int index)
{
	int	i;
	int	pos;

	i = index;
	pos = 1;
	scene->has_light = true;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			if (pos == 4)
				return (set_light_brightness(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			set_light_pos(&scene->light, line + index, pos);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (-1);
}

void	set_sp_pos(t_sphere *sphere, char *line, int pos)
{
	if (pos == 1)
		sphere->center.x = ft_atoi(line);
	else if (pos == 2)
		sphere->center.y = ft_atoi(line);
	else
		sphere->center.z = ft_atoi(line);
}

int	set_sp_diameter(t_scene *scene, char *line, int index)
{
	int	i;
	int	pos;

	i = index;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			scene->spheres.
		}
	}
	return (1);
}

int set_sphere(char *line, t_scene *scene, int index)
{
	int	i;
	int	pos;

	i = index;
	pos = 1;
	scene->nb_spheres++;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			if (pos == 4)
				return (set_sp_diameter(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			set_sp_pos(&scene->spheres, line + index, pos);
			pos++;
			index = i;
		}
		else
			index++;
	}
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

void	prepare_scene(t_scene *scene)
{
	scene->has_ambient = false;
	scene->has_camera = false;
	scene->has_light = false;
	scene->nb_cylinders = 0;
	scene->nb_lights = 0;
	scene->nb_planes = 0;
	scene->nb_spheres = 0;
}

int main(int ac, char **av)
{
	t_scene	scene;

	prepare_scene(&scene);
	if (ac == 2)
	{
		if (check_file(av[1], &scene) == -1)
			write(2, "Error\n", 6);
	}
	else
		printf("error argument\n");
	printf("ratio %f\n", scene.ambient.ratio);
	printf("colors: %d, %d, %d\n", scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	printf("camera.fov: %f\n", scene.camera.fov);
	printf("camera.position.x: %f\n", scene.camera.position.x);
	printf("camera.position.y: %f\n", scene.camera.position.y);
	printf("camera.position.z: %f\n", scene.camera.position.z);
	printf("camera.orientation.x: %f\n", scene.camera.orientation.x);
	printf("camera.orientation.y: %f\n", scene.camera.orientation.y);
	printf("camera.orientation.z: %f\n", scene.camera.orientation.z);
	printf("light.position.x %f\n", scene.light.position.x);
	printf("light.position.y %f\n", scene.light.position.y);
	printf("light.position.z %f\n", scene.light.position.z);
	printf("camera.light.brightness %f\n", scene.light.brightness);
}
