/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:47:28 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 16:25:00 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_ambient_ratio(char *line, t_scene *scene, int index)
{
	double	ratio;
	int		end;

	if (scene->has_ambient)
		return (printf("Error: Duplicate ambient light definition\n"), -1);
	index = skip_whitespace(line, index + 1);
	if (!safe_atof(line + index, &ratio, &end) || line[index + end] != ' ')
		return (printf("Error: Invalid ambient ratio\n"), -1);
	if (!validate_ratio(ratio))
		return (-1);
	scene->ambient.ratio = ratio;
	index += end;
	if (parse_color(line, &scene->ambient.color, index) == -1)
		return (-1);
	scene->has_ambient = true;
	return (1);
}
