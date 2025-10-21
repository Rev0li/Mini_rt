/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:40:43 by yafahfou          #+#    #+#             */
/*   Updated: 2025/10/21 13:20:04 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	free_partial_scene(t_scene *scene)
{
	if (scene->spheres)
	{
		free(scene->spheres);
		scene->spheres = NULL;
	}
	if (scene->cylinders)
	{
		free(scene->cylinders);
		scene->cylinders = NULL;
	}
	if (scene->planes)
	{
		free(scene->planes);
		scene->planes = NULL;
	}
	return (-1);
}

int	alloc_data(t_scene *scene)
{
	if (scene->nb_spheres != 0)
	{
		scene->spheres = ft_calloc(scene->nb_spheres, sizeof(t_sphere));
		if (!scene->spheres)
			return (free_partial_scene(scene));
	}
	if (scene->nb_cylinders != 0)
	{
		scene->cylinders = ft_calloc(scene->nb_cylinders, sizeof(t_cylinder));
		if (!scene->cylinders)
			return (free_partial_scene(scene));
	}
	if (scene->nb_planes != 0)
	{
		scene->planes = ft_calloc(scene->nb_planes, sizeof(t_plane));
		if (!scene->planes)
			return (free_partial_scene(scene));
	}
	return (0);
}

void	set_data(char *line, t_scene *scene)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 's' && line[i + 1] == 'p')
			scene->nb_spheres++;
		else if (line[i] == 'c' && line[i + 1] == 'y')
			scene->nb_cylinders++;
		else if (line[i] == 'p' && line[i + 1] == 'l')
			scene->nb_planes++;
		i++;
	}
}

int	get_data_from_file(char *file, t_scene *scene)
{
	char	*line;
	int		fd;

	if (safe_open(file, &fd) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		set_data(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (alloc_data(scene) == -1)
	{
		printf("Error: calloc object\n");
		return (-1);
	}
	return (0);
}
