/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:46:13 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/24 12:10:42 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

void refresh_image(t_mlx *data) {
  /*// Check if the image pointer is valid before trying to destroy it*/
  /*if (data->img)*/
  /*{*/
  /*    mlx_destroy_image(data->mlx, data->img);*/
  /*}*/
  /**/
  /*// Create a new image*/
  /*data->img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);*/
  /**/
  /*// It's also crucial to check if the new image was created successfully*/
  /*if (!data->img)*/
  /*{*/
  /*    // Handle error: couldn't create image*/
  /*    // For example, print an error message and exit*/
  /*    printf("Error: Could not create new image.\n");*/
  /*    return;*/
  /*}*/

  mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}

int key_hook(int keycode, t_mlx *data) {

  printf("Keyboard keycode : %d\n", keycode);
  /*printf("Key pressed: %d\n", keycode);*/
  if (keycode == 65453) // +
    data->scene.ambient.ratio -= 0.05;
  else if (keycode == 65451) // -
    data->scene.ambient.ratio += 0.05;
  else if (keycode == 119) // W
    data->scene.camera.position.z -= 0.1;
  else if (keycode == 115) // S
    data->scene.camera.position.z += 0.1;
  else if (keycode == 97) // D
    data->scene.camera.orientation.x -= 0.01;
  else if (keycode == 100) // A
    data->scene.camera.orientation.x += 0.01;
  else if (keycode == 101) // E
    data->scene.camera.position.y += 0.1;
  else if (keycode == 113) // Q
    data->scene.camera.position.y -= 0.1;
  else if (keycode == 65307)
    destroy_hook(data);

  refresh_image(data);
  return (0);
}
