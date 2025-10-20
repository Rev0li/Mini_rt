/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:38:04 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:37:31 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_light(char *line, t_scene *scene, int index)
{
	double	brightness;
	int		end;

	if (scene->has_light)
		return (printf("Error: Duplicate light definition\n"), -1);
	index = skip_whitespace(line, index + 1);
	if (parse_coordinates(line, &scene->light.position, &index) == -1)
		return (-1);
	index = skip_whitespace(line, index);
	if (!safe_atof(line + index, &brightness, &end))
		return (printf("Error: Invalid light brightness\n"), -1);
	if (!validate_ratio(brightness))
		return (-1);
	scene->light.brightness = brightness;
	index += end;
	if (parse_color(line, &scene->light.color, index) == -1)
		return (-1);
	scene->has_light = true;
	return (1);
}
