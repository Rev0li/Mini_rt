/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_set_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:25:20 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 11:25:52 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_cy_normal(t_scene *scene, char *line, int pos)
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

int	set_cy_center(t_scene *scene, char *line, int pos)
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
