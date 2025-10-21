/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:39:37 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 16:33:46 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

static int	parse_cylinder_dimensions(char *line, int *index, t_cylinder *cy)
{
	double	value;
	int		end;

	*index = skip_whitespace(line, *index);
	if (!safe_atof(line + *index, &value, &end))
		return (printf("Error: Invalid cylinder diameter\n"), -1);
	if (!validate_positive(value))
		return (-1);
	cy->diameter = value;
	*index += end;
	*index = skip_whitespace(line, *index);
	if (!safe_atof(line + *index, &value, &end))
		return (printf("Error: Invalid cylinder height\n"), -1);
	if (!validate_positive(value))
		return (-1);
	cy->height = value;
	*index += end;
	return (0);
}

int	set_cylinder(char *line, t_scene *scene, int index)
{
	t_cylinder	*cy;
	int			i;

	i = scene->cylinder_index;
	cy = &scene->cylinders[i];
	index = skip_whitespace(line, index + 2);
	if (parse_coordinates(line, &cy->center, &index) == -1)
		return (-1);
	if (parse_normalized_vector(line, &cy->axis, &index) == -1)
		return (-1);
	if (parse_cylinder_dimensions(line, &index, cy) == -1)
		return (-1);
	if (parse_color(line, &cy->color, index) == -1)
		return (-1);
	scene->cylinder_index++;
	return (1);
}
