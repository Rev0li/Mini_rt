/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:47:28 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/24 12:02:34 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int set_ambient_ratio(char *line, t_scene *scene, int index)
{
	size_t i;

	i = index;
	scene->has_ambient = true;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			scene->ambient.ratio = ft_atoi(line + index);
			if (0.0 > scene->ambient.ratio || scene->ambient.ratio > 1.0)
				return (-1);
			index = i;
			return (parse_color(line, &scene->ambient.color, index));
		}
		else
			index++;
	}
	return (1);
}
