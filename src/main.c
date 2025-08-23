/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:04 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/22 16:13:55 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void set_light_pos(t_light *light, char *line, int pos)
{
	if (pos == 1)
		light->position.x = ft_atoi(line);
	if (pos == 2)
		light->position.y = ft_atoi(line);
	else
		light->position.z = ft_atoi(line);
}

int set_light_brightness(t_scene *scene, char *line, int index)
{
	scene->light.brightness = ft_atoi(line + index);
	if (scene->light.brightness < 0 || scene->light.brightness > 1)
		return (-1);
	return (1);
}

int set_light(char *line, t_scene *scene, int index)
{
	int i;
	int pos;

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

void set_sp_pos(t_scene *scene, char *line, int pos)
{
	if (pos == 1)
		scene->spheres[scene->sphere_index].center.x = ft_atoi(line);
	else if (pos == 2)
		scene->spheres[scene->sphere_index].center.y = ft_atoi(line);
	else
		scene->spheres[scene->sphere_index].center.z = ft_atoi(line);
}

int set_sp_diameter(t_scene *scene, char *line, int index)
{
	int i;
	int res;

	res = 1;
	printf("line %s\n", line);
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			scene->spheres[scene->sphere_index].diameter = ft_atoi(line);
			index = i;
			res = parse_color(line + index, &scene->spheres[scene->sphere_index].color, index);
			break;
		}
		else
			index++;
	}
	scene->sphere_index++;
	return (res);
}

int set_sphere(char *line, t_scene *scene, int index)
{
	int i;
	int pos;

	i = index;
	pos = 1;
	while (line[index])
	{
		if (is_digit(line[index]) || (line[index] == '-' && is_digit(line[index + 1])))
		{
			if (pos == 4)
			{
				scene->sphere_index++;
				return (set_sp_diameter(scene, line + index, index));
			}
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))) || line[i] == '-')
				i++;
			set_sp_pos(scene, line + index, pos);
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
	(void)index;
	return (1);
}

int set_cylinder(char *line, t_scene *scene, int index)
{
	(void)line;
	(void)scene;
	(void)index;
	return (1);
}

void prepare_scene(t_scene *scene)
{
	scene->has_ambient = false;
	scene->has_camera = false;
	scene->has_light = false;
	scene->nb_cylinders = 0;
	scene->nb_lights = 0;
	scene->nb_planes = 0;
	scene->nb_spheres = 0;
	scene->sphere_index = 0;
	scene->plane_index = 0;
	scene->cylinder_index = 0;
}

int main(int ac, char **av)
{
	t_scene scene;

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
	printf("sphere.center.x %f\n", scene.spheres[1].center.x);
	printf("sphere.center.y %f\n", scene.spheres[1].center.y);
	printf("sphere.center.z %f\n", scene.spheres[1].center.z);
	printf("sphere numb %d\n", scene.nb_spheres);
	printf("sphere.diameter %f\nr", scene.spheres[0].diameter);
}
