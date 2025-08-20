/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:48:31 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/20 18:02:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/mini_rt.h"

// Initialise une scène simple avec une caméra, une sphère et un plan
t_scene init_hardcoded_scene(void)
{
    t_scene scene;

    // Caméra : positionnée à (0,0,0), regarde vers -Z, FOV = 70°
    scene.camera.position = (t_vec3){0, 0, 0};
    scene.camera.orientation = (t_vec3){0, 0, -1};
    scene.camera.fov = 70.0;

    // Sphère : centre à (0,0,-5), rayon = 1, couleur rouge
    scene.sphere.center = (t_vec3){0, 0, -5};
    scene.sphere.radius = 1.0;
    scene.sphere.color = (t_color){255, 0, 0};

    // Plan : point à (0,-1,0), normale vers le haut (0,1,0), couleur bleue
    scene.plane.point = (t_vec3){0, -1, 0};
    scene.plane.normal = (t_vec3){0, 1, 0};
    scene.plane.color = (t_color){0, 0, 255};

    return scene;
}


int	main  (int argc, char **argv)
{
	t_mlx	*data;

	data = NULL;
	if (argc == 2)
	{
		printf("%s\n", argv[1]);// check argv[1] before parse
		// if file or contained is not good return (1)
		data = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
		if (init_app(data))
		{
	        t_scene scene = init_hardcoded_scene();
			draw(data, scene);
			mlx_hook(data->window, 2, 1L << 0, key_hook, data);
			mlx_hook(data->window, 17, 0, destroy_hook, data);
			mlx_loop(data->mlx);
		}
		else
		{
			printf("Fail init app\n");
			return (1);
		}
	}
	printf("Usage: ./miniRT MAP_FILE.rt\n");
	return (1);
}
