/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:04 by yafahfou          #+#    #+#             */
/*   Updated: 2025/09/15 18:41:16 by yassinefahf      ###   ########.fr       */
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

int set_sp_pos(t_scene *scene, char *line, int pos)
{
	// int check;

	// check = ft_atoi(line);
	// if (check == 0 && line[0] != '0')
	// 	return (-1);
	if (pos == 1)
		scene->spheres[scene->sphere_index].center.x = ft_atoi(line);
	else if (pos == 2)
		scene->spheres[scene->sphere_index].center.y = ft_atoi(line);
	else
		scene->spheres[scene->sphere_index].center.z = ft_atoi(line);
	return (1);
}

int set_sp_diameter(t_scene *scene, char *line, int index)
{
	int i;
	int res;

	res = 1;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			scene->spheres[scene->sphere_index].diameter = ft_atoi(line + index);
			index = i;
			res = parse_color(line, &scene->spheres[scene->sphere_index].color, index);
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
				return (set_sp_diameter(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))) || line[i] == '-')
				i++;
			if (set_sp_pos(scene, line + index, pos) == -1)
				return (-1);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (1);
}

int set_pl_point(t_scene *scene, char *line, int pos)
{
	// int check;

	// check = ft_atoi(line);
	// if (check == 0 && line && line[0] != '0')
	// 	return (-1);
	if (pos == 1)
		scene->planes[scene->plane_index].point.x = ft_atoi(line);
	else if (pos == 2)
		scene->planes[scene->plane_index].point.y = ft_atoi(line);
	else
		scene->planes[scene->plane_index].point.z = ft_atoi(line);
	return (1);
}

int set_pl_vector(t_scene *scene, char *line, int pos)
{
	int check;

	check = ft_atoi(line);
	// if (check == 0 && line[0] != '0')
	// 	return (-1);
	if (pos == 1)
		scene->planes[scene->plane_index].normal.x = ft_atoi(line);
	else if (pos == 2)
		scene->planes[scene->plane_index].normal.y = ft_atoi(line);
	else
		scene->planes[scene->plane_index].normal.z = ft_atoi(line);
	if (check < -1 || check > 1)
		return (-1);
	return (1);
}

int set_pl_normal(t_scene *scene, char *line, int index)
{
	int i;
	int pos;
	int res;

	i = index;
	pos = 1;
	res = 1;
	while (line[index])
	{
		if (is_digit(line[index]) || (line[index] == '-' && is_digit(line[index + 1])))
		{
			if (pos == 4)
			{
				res = parse_color(line, &scene->planes[scene->plane_index].color, index);
				scene->plane_index++;
				break;
			}
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))) || line[i] == '-')
				i++;
			if (set_pl_vector(scene, line + index, pos) == -1)
				return (-1);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (res);
}

int set_plane(char *line, t_scene *scene, int index)
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
				return (set_pl_normal(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))) || line[i] == '-')
				i++;
			if (set_pl_point(scene, line + index, pos) == -1)
				return (-1);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (1);
}

int set_cy_normal(t_scene *scene, char *line, int pos)
{
	// int check;

	// check = ft_atoi(line);
	// if (check == 0 && line && line[0] != '0')
	// 	return (-1);
	if (pos == 1)
		scene->cylinders[scene->cylinder_index].axis.x = ft_atoi(line);
	if (pos == 2)
		scene->cylinders[scene->cylinder_index].axis.y = ft_atoi(line);
	else
		scene->cylinders[scene->cylinder_index].axis.z = ft_atoi(line);
	return (1);
}

int set_cy_center(t_scene *scene, char *line, int pos)
{
	// int check;

	// check = ft_atoi(line);
	// if (check == 0 && line && line[0] != '0')
	// 	return (-1);
	if (pos == 1)
		scene->cylinders[scene->cylinder_index].center.x = ft_atoi(line);
	if (pos == 2)
		scene->cylinders[scene->cylinder_index].center.y = ft_atoi(line);
	else
		scene->cylinders[scene->cylinder_index].center.z = ft_atoi(line);
	// if (check < 1 || check > 1)
	// 	return (-1);
	return (1);
}

int set_cy_height(t_scene *scene, char *line, int index)
{
	int i;
	int res;

	res = 1;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			scene->cylinders[scene->cylinder_index].height = ft_atoi(line + index);
			index = i;
			res = parse_color(line, &scene->cylinders[scene->cylinder_index].color, index);
			break;
		}
		else
			index++;
	}
	scene->cylinder_index++;
	return (res);
}

int set_cy_diameter(t_scene *scene, char *line, int index)
{
	int i;

	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			scene->cylinders[scene->cylinder_index].diameter = ft_atoi(line + index);
			index = i;
			return (set_cy_height(scene, line, index));
		}
		else
			index++;
	}
	return (1);
}

int parse_cy_normal(t_scene *scene, char *line, int index)
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
				return (set_cy_diameter(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))) || line[i] == '-')
				i++;
			if (set_cy_normal(scene, line + index, pos) == -1)
				return (-1);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (1);
}

int set_cylinder(char *line, t_scene *scene, int index)
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
				return (parse_cy_normal(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))) || line[i] == '-')
				i++;
			if (set_cy_center(scene, line + index, pos) == -1)
				return (-1);
			pos++;
			index = i;
		}
		else
			index++;
	}
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

t_ray create_test_ray(void)
{
	t_ray ray;

	ray.origin = (t_vec3){0.0, 0.0, 0.0};
	ray.direction = (t_vec3){0.0, 0.0, -1.0};
	return (ray);
}

void set_vec(t_vec3 *vec1, double x, double y, double z)
{
	vec1->x = x;
	vec1->y = y;
	vec1->z = z;
}

t_ray create_ray_from_pixel(int x, int y, t_camera *cam, t_mlx *data)
{
	t_ray ray;
	float aspect_ratio;
	float rad_fov;
	double new_x;
	double new_y;
	t_vec3 forward;
	t_vec3 fake_up;
	t_vec3 up;
	t_vec3 right;

	new_x = 2 * (x / (double)data->width) - 1;
	new_y = -(2 * (y / (double)data->height) - 1);
	aspect_ratio = (float)data->width / (float)data->height;
	rad_fov = cam->fov * (M_PI / 180);
	new_x = (new_x * aspect_ratio) * tan(rad_fov / 2);
	new_y = new_y * tan(rad_fov / 2);
	set_vec(&forward, cam->orientation.x, cam->orientation.y, cam->orientation.z);
	forward = vec_normalize(forward);
	set_vec(&fake_up, 0, 1, 0);
	right = vec_normalize(vec_cross(forward, fake_up));
	up = vec_cross(forward, right);
	set_vec(&ray.origin, cam->position.x, cam->position.y, cam->position.z);
	ray.direction = vec_add(vec_add(vec_scale(right, new_x), vec_scale(up, new_y)), forward);
	return (ray);
}

void test_ray_display(t_mlx *data, t_scene scene)
{
	int x;
	int y;
	t_ray ray;

	(void)ray;
	printf("Rayon créé:\n");
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
	scene.camera.position.x = 0;
	scene.camera.position.y = 0;
	scene.camera.position.z = 0;
	scene.camera.orientation.x = 0;
	scene.camera.orientation.y = 0;
	scene.camera.orientation.z = -1;
	scene.camera.fov = 90;
	ray = create_ray_from_pixel(500, 500, &scene.camera, data);
	printf("ray: %f , %f, %f\n", ray.direction.x, ray.direction.y, ray.direction.z);
}

int main(int ac, char **av)
{
	t_scene scene;
	t_mlx data;

	prepare_scene(&scene);
	if (ac == 2)
	{
		if (check_file(av[1], &scene) == -1)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (init_app(&data))
		{
			test_ray_display(&data, scene);
			// draw(data, scene);
			/*draw3d(data, scene);*/
			mlx_hook(data.window, 2, 1L << 0, key_hook, &data);
			mlx_hook(data.window, 17, 0, destroy_hook, &data);
			mlx_loop(data.mlx);
		}
	}
	else
		printf("error argument\n");
	// 	printf("ratio %f\n", scene.ambient.ratio);
	// 	printf("colors: %d, %d, %d\n", scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	// 	printf("camera.fov: %f\n", scene.camera.fov);
	// 	printf("camera.position.x: %f\n", scene.camera.position.x);
	// 	printf("camera.position.y: %f\n", scene.camera.position.y);
	// 	printf("camera.position.z: %f\n", scene.camera.position.z);
	// 	printf("camera.orientation.x: %f\n", scene.camera.orientation.x);
	// 	printf("camera.orientation.y: %f\n", scene.camera.orientation.y);
	// 	printf("camera.orientation.z: %f\n", scene.camera.orientation.z);
	// 	printf("light.position.x %f\n", scene.light.position.x);
	// 	printf("light.position.y %f\n", scene.light.position.y);
	// 	printf("light.position.z %f\n", scene.light.position.z);
	// 	printf("camera.light.brightness %f\n", scene.light.brightness);
	// 	printf("sphere.center.x %f\n", scene.spheres[0].center.x);
	// 	printf("sphere.center.y %f\n", scene.spheres[0].center.y);
	// 	printf("sphere.center.z %f\n", scene.spheres[0].center.z);
	// 	printf("sphere numb %d\n", scene.nb_spheres);
	// 	printf("sphere.diameter %f\nr", scene.spheres[0].diameter);
	// 	printf("colors: %d, %d, %d\n", scene.spheres[2].color.r, scene.spheres[2].color.g, scene.spheres[2].color.b);
	// 	printf("plane.point.x %f\n", scene.planes[1].point.x);
	// 	printf("plane.point.y %f\n", scene.planes[1].point.y);
	// 	printf("plane.point.z %f\n", scene.planes[1].point.z);
	// 	printf("plane numb %d\n", scene.nb_planes);
	// 	printf("plane.normal.x %f\n", scene.planes[1].normal.x);
	// 	printf("plane.normal.y %f\n", scene.planes[1].normal.y);
	// 	printf("plane.normal.z %f\n", scene.planes[1].normal.z);
	// 	printf("plane colors: %d, %d, %d\n", scene.planes[0].color.r, scene.planes[0].color.g, scene.planes[0].color.b);
	// 	printf("cyl.center.x %f\n", scene.cylinders[1].center.x);
	// 	printf("cyl.center.y %f\n", scene.cylinders[1].center.y);
	// 	printf("cyl.center.z %f\n", scene.cylinders[1].center.z);
	// 	printf("cyl.normal.x %f\n", scene.cylinders[1].axis.x);
	// 	printf("cyl.normal.y %f\n", scene.cylinders[1].axis.y);
	// 	printf("cyl.normal.z %f\n", scene.cylinders[1].axis.z);
	// 	printf("cyl diameter %f\n", scene.cylinders[1].diameter);
	// 	printf("cyl height %f\n", scene.cylinders[1].height);
	// 	printf("cyl colors: %d, %d, %d\n", scene.cylinders[1].color.r, scene.cylinders[1].color.g, scene.cylinders[1].color.b);
}
