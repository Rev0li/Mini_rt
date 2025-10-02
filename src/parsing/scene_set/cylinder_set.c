/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:39:37 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/29 19:21:08 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_cy_height(t_scene *scene, char *line, int index)
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
			scene->cylinders[scene->cylinder_index].height
				= ft_atoi(line + index);
			index = i;
			res = parse_color(line,
					&scene->cylinders[scene->cylinder_index].color, index);
			break ;
		}
		else
			index++;
	}
	scene->cylinder_index++;
	return (res);
}

int	set_cy_diameter(t_scene *scene, char *line, int index)
{
	int	i;

	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_part_of_number(line[i], line[i + 1]))
				i++;
			scene->cylinders[scene->cylinder_index].diameter
				= ft_atoi(line + index);
			index = i;
			return (set_cy_height(scene, line, index));
		}
		else
			index++;
	}
	return (1);
}

int	parse_cy_normal(t_scene *scene, char *line, int index)
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
				return (set_cy_diameter(scene, line, index));
			i = index;
			while (is_part_of_number(line[i], line[i + 1]))
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

int	set_cylinder(char *line, t_scene *scene, int index)
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
				return (parse_cy_normal(scene, line, index));
			i = index;
			while (is_part_of_number(line[i], line[i + 1]))
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
