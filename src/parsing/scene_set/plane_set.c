/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:38:47 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:38:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_plane(char *line, t_scene *scene, int index)
{
	int	i;

	i = scene->plane_index;
	index = skip_whitespace(line, index + 2);
	if (parse_coordinates(line, &scene->planes[i].point, &index) == -1)
		return (-1);
	if (parse_normalized_vector(line, &scene->planes[i].normal, &index) == -1)
		return (-1);
	if (parse_color(line, &scene->planes[i].color, index) == -1)
		return (-1);
	scene->plane_index++;
	return (1);
}
