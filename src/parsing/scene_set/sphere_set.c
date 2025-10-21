/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:35:52 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:37:54 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_sphere(char *line, t_scene *scene, int index)
{
	double	diameter;
	int		end;
	int		i;

	i = scene->sphere_index;
	index = skip_whitespace(line, index + 2);
	if (parse_coordinates(line, &scene->spheres[i].center, &index) == -1)
		return (-1);
	index = skip_whitespace(line, index);
	if (!safe_atof(line + index, &diameter, &end))
		return (printf("Error: Invalid sphere diameter\n"), -1);
	if (!validate_positive(diameter))
		return (-1);
	scene->spheres[i].diameter = diameter;
	index += end;
	if (parse_color(line, &scene->spheres[i].color, index) == -1)
		return (-1);
	scene->sphere_index++;
	return (1);
}
