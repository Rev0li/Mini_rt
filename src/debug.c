/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 08:21:22 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/29 16:48:43 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

unsigned int	return_color(t_hit_objet obj, t_scene scene)
{
	unsigned int	color;

		if (obj.form == SPHERE)
			color = scene.spheres[obj.index].color.hex;
		if (obj.form == PLANE)
			color = scene.planes[obj.index].color.hex;
		if (obj.form == CYLINDRE)
			color = scene.cylinders[obj.index].color.hex;
	return (color);
}

void	print_data(t_scene	scene)
{	
	printf("ratio %f\n", scene.ambient.ratio);
	printf("colors: %d, %d, %d\n", scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	printf("camera.fov: %f\n", scene.camera.fov);
	printf("camera.position.x: %f\n", scene.camera.position.x);
	printf("camera.position.y: %f\n", scene.camera.position.y);
	printf("camera.position.z: %f\n", scene.camera.position.z);
	printf("camera.orientation.x: %f\n", scene.camera.orientation.x);
	printf("camera.orientation.y: %f\n", scene.camera.orientation.y);
	printf("camera.orientation.z: %f\n", scene.camera.orientation.z);
	printf("light.position.x %f\n", scene.lights->position.x);
	printf("light.position.y %f\n", scene.lights->position.y);
	printf("light.position.z %f\n", scene.lights->position.z);
	printf("camera.light.brightness %f\n", scene.lights->brightness);
	printf("sphere.center.x %f\n", scene.spheres[0].center.x);
	printf("sphere.center.y %f\n", scene.spheres[0].center.y);
	printf("sphere.center.z %f\n", scene.spheres[0].center.z);
	printf("sphere numb %d\n", scene.nb_spheres);
	printf("sphere.diameter %f\nr", scene.spheres[0].diameter);
	printf("colors: %d, %d, %d\n", scene.spheres[2].color.r, scene.spheres[2].color.g, scene.spheres[2].color.b);
	// printf("plane.point.x %f\n", scene.planes[1].point.x);
	// printf("plane.point.y %f\n", scene.planes[1].point.y);
	// printf("plane.point.z %f\n", scene.planes[1].point.z);
	// printf("plane numb %d\n", scene.nb_planes);
	// printf("plane.normal.x %f\n", scene.planes[1].normal.x);
	// printf("plane.normal.y %f\n", scene.planes[1].normal.y);
	// printf("plane.normal.z %f\n", scene.planes[1].normal.z);
	// printf("plane colors: %d, %d, %d\n", scene.planes[0].color.r, scene.planes[0].color.g, scene.planes[0].color.b);
	// printf("cyl.center.x %f\n", scene.cylinders[1].center.x);
	// printf("cyl.center.y %f\n", scene.cylinders[1].center.y);
	// printf("cyl.center.z %f\n", scene.cylinders[1].center.z);
	// printf("cyl.normal.x %f\n", scene.cylinders[1].axis.x);
	// printf("cyl.normal.y %f\n", scene.cylinders[1].axis.y);
	// printf("cyl.normal.z %f\n", scene.cylinders[1].axis.z);
	// printf("cyl diameter %f\n", scene.cylinders[1].diameter);
	// printf("cyl height %f\n", scene.cylinders[1].height);
	// printf("cyl colors: %d, %d, %d\n", scene.cylinders[1].color.r, scene.cylinders[1].color.g, scene.cylinders[1].color.b);
}
