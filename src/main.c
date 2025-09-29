/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:04 by yafahfou          #+#    #+#             */
/*   Updated: 2025/09/24 13:46:19 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

void prepare_scene(t_scene *scene) {
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
  scene->light_index = 0;
}

int main(int ac, char **av) {
  t_scene scene;
  t_mlx *data;

  data = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
  prepare_scene(&scene);
  if (ac == 2) {
    if (check_file(av[1], &scene) == -1) {
      write(2, "Error\n", 6);
      exit(EXIT_FAILURE);
    }
    data->scene = scene;
    print_data(data->scene);
    loop(data);
  } else
    printf("error argument\n");
}
