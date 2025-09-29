/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:35:52 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/29 19:21:09 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_sp_pos(t_scene *scene, char *line, int pos)
{
	int	check;

	check = ft_atoi(line);
	if (check == 0 && line[0] != '0')
		return (-1);
	if (pos == 1)
		scene->spheres[scene->sphere_index].center.x = ft_atoi(line);
	else if (pos == 2)
		scene->spheres[scene->sphere_index].center.y = ft_atoi(line);
	else
		scene->spheres[scene->sphere_index].center.z = ft_atoi(line);
	return (1);
}

int	set_sp_diameter(t_scene *scene, char *line, int index)
{
	int	i;
	int	res;

	res = 1;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_part_of_number(line[i], line[i + 1]))
				i++;
			scene->spheres[scene->sphere_index].diameter
				= ft_atoi(line + index);
			index = i;
			res = parse_color(line,
					&scene->spheres[scene->sphere_index].color, index);
			break ;
		}
		else
			index++;
	}
	scene->sphere_index++;
	return (res);
}

int	set_sphere(char *line, t_scene *scene, int index)
{
	int	i;
	int	pos;

	i = index;
	pos = 1;
	while (line[index])
	{
		if (is_valid_number_start(line[index], line[index + 1]))
		{
			if (pos == 4)
				return (set_sp_diameter(scene, line, index));
			i = index;
			while (is_part_of_number(line[i], line[i + 1]))
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
