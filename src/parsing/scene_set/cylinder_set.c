/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:39:37 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:38:35 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_cylinder(char *line, t_scene *scene, int index)
{
	double	diameter;
	double	height;
	int		end;
	int		i;

	i = scene->cylinder_index;
	index = skip_whitespace(line, index + 2);
	if (parse_coordinates(line, &scene->cylinders[i].center, &index) == -1)
		return (-1);
	if (parse_normalized_vector(line, &scene->cylinders[i].axis, &index) == -1)
		return (-1);
	index = skip_whitespace(line, index);
	if (!safe_atof(line + index, &diameter, &end))
		return (printf("Error: Invalid cylinder diameter\n"), -1);
	if (!validate_positive(diameter))
		return (-1);
	scene->cylinders[i].diameter = diameter;
	index += end;
	index = skip_whitespace(line, index);
	if (!safe_atof(line + index, &height, &end))
		return (printf("Error: Invalid cylinder height\n"), -1);
	if (!validate_positive(height))
		return (-1);
	scene->cylinders[i].height = height;
	index += end;
	if (parse_color(line, &scene->cylinders[i].color, index) == -1)
		return (-1);
	scene->cylinder_index++;
	return (1);
}
