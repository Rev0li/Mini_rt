/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:38:04 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/24 13:38:19 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

void set_light_pos(t_light *light, char *line, int pos)
{
	if (pos == 1)
		light->position.x = ft_atoi(line);
	if (pos == 2)
		light->position.y = ft_atoi(line);
	else
		light->position.z = ft_atoi(line);
}

int set_light_brightness(t_scene *scene, char *line, int index)
{
	scene->light.brightness = ft_atoi(line + index);
	if (scene->light.brightness < 0 || scene->light.brightness > 1)
		return (-1);
	return (1);
}

int set_light(char *line, t_scene *scene, int index)
{
	int i;
	int pos;

	i = index;
	pos = 1;
	scene->has_light = true;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			if (pos == 4)
				return (set_light_brightness(scene, line, index));
			i = index;
			while (is_digit(line[i]) || (line[i] == '.' && (is_digit(line[i + 1]))))
				i++;
			set_light_pos(&scene->light, line + index, pos);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (-1);
}
