/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:38:47 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 13:05:02 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	set_pl_point(t_scene *scene, char *line, int pos)
{
	int	check;

	check = ft_atoi(line);
	if (check == 0 && line && line[0] != '0')
		return (-1);
	if (pos == 1)
		scene->planes[scene->plane_index].point.x = ft_atoi(line);
	else if (pos == 2)
		scene->planes[scene->plane_index].point.y = ft_atoi(line);
	else
		scene->planes[scene->plane_index].point.z = ft_atoi(line);
	return (1);
}

int	set_pl_vector(t_scene *scene, char *line, int pos)
{
	int	check;

	check = ft_atoi(line);
	if (check == 0 && line[0] != '0')
		return (-1);
	if (pos == 1)
		scene->planes[scene->plane_index].normal.x = ft_atoi(line);
	else if (pos == 2)
		scene->planes[scene->plane_index].normal.y = ft_atoi(line);
	else
		scene->planes[scene->plane_index].normal.z = ft_atoi(line);
	if (check < -1 || check > 1)
		return (-1);
	return (1);
}

int	parse_plane_values(t_scene *scene, char *line, int *index, int *pos)
{
	int	i;

	i = *index;
	while (is_part_of_number(line[i], line[i + 1]))
		i++;
	if (set_pl_vector(scene, line + *index, *pos) == -1)
		return (-1);
	(*pos)++;
	*index = i;
	return (1);
}

int	set_pl_normal(t_scene *scene, char *line, int index)
{
	int	pos;
	int	res;

	pos = 1;
	res = 1;
	while (line[index])
	{
		if (is_valid_number_start(line[index], line[index + 1]))
		{
			if (pos == 4)
			{
				res = parse_color(line,
						&scene->planes[scene->plane_index].color, index);
				scene->plane_index++;
				break ;
			}
			res = parse_plane_values(scene, line, &index, &pos);
			if (res == -1)
				return (-1);
		}
		else
			index++;
	}
	return (res);
}

int	set_plane(char *line, t_scene *scene, int index)
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
				return (set_pl_normal(scene, line, index));
			i = index;
			while (is_part_of_number(line[i], line[i + 1]))
				i++;
			if (set_pl_point(scene, line + index, pos) == -1)
				return (-1);
			pos++;
			index = i;
		}
		else
			index++;
	}
	return (1);
}
