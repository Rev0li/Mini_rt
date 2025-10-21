/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 08:21:22 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 17:09:45 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

void	print_vec3(t_vec3 vec, char *name)
{
	printf("%s: (x: %.2f, y: %.2f, z: %.2f)\n", name, vec.x, vec.y, vec.z);
}

void	print_color(t_color color, char *name)
{
	printf("%s: (r: %d, g: %d, b: %d, hex: %#06x)\n", name,
		color.r, color.g, color.b, color.hex);
}

void	print_data(t_scene *scene)
{
	printf("=== SCENE DATA ===\n");

	// Ambient
	if (scene->has_ambient)
	{
		printf("\n[Ambient Light]\n");
		printf("Ratio: %.2f\n", scene->ambient.ratio);
		print_color(scene->ambient.color, "Color");
	}
	else
		printf("\n[Ambient Light] Not set\n");

	// Camera
	if (scene->has_camera)
	{
		printf("\n[Camera]\n");
		print_vec3(scene->camera.position, "Position");
		print_vec3(scene->camera.orientation, "Orientation");
		printf("FOV: %.2f\n", scene->camera.fov);
	}
	else
		printf("\n[Camera] Not set\n");

	// Light
	if (scene->has_light)
	{
		printf("\n[Light]\n");
		print_vec3(scene->light.position, "Position");
		printf("Brightness: %.2f\n", scene->light.brightness);
		print_color(scene->light.color, "Color");
	}
	else
		printf("\n[Light] Not set\n");

	// Spheres
	printf("\n[Spheres] Count: %d\n", scene->nb_spheres);
	for (int i = 0; i < scene->nb_spheres; i++)
	{
		printf("  Sphere %d:\n", i);
		print_vec3(scene->spheres[i].center, "    Center");
		printf("    Radius: %.2f\n", scene->spheres[i].radius);
		printf("    Diameter: %.2f\n", scene->spheres[i].diameter);
		print_color(scene->spheres[i].color, "    Color");
	}

	// Planes
	printf("\n[Planes] Count: %d\n", scene->nb_planes);
	for (int i = 0; i < scene->nb_planes; i++)
	{
		printf("  Plane %d:\n", i);
		print_vec3(scene->planes[i].point, "    Point");
		print_vec3(scene->planes[i].normal, "    Normal");
		print_color(scene->planes[i].color, "    Color");
	}

	// Cylinders 
    printf("\n[Cylinders] Count: %d\n", scene->nb_cylinders);
    for (int i = 0; i < scene->nb_cylinders; i++)
    {
        printf("  Cylinder %d:\n", i);
        print_vec3(scene->cylinders[i].center, "    Center");
        print_vec3(scene->cylinders[i].axis, "    Axis");
        printf("    Diameter: %.2f\n", scene->cylinders[i].diameter);
        printf("    Height: %.2f\n", scene->cylinders[i].height);
        print_color(scene->cylinders[i].color, "    Color");
    }
	printf("\n=== END OF DATA ===\n");
}

