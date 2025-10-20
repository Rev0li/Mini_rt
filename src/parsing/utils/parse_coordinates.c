/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:36:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:37:03 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	parse_coordinates(char *line, t_vec3 *vec, int *idx)
{
	double	coords[3];
	int		i;
	int		end;

	i = 0;
	*idx = skip_whitespace(line, *idx);
	while (i < 3 && line[*idx])
	{
		if (!is_valid_number_start(line[*idx], line[*idx + 1]))
		{
			(*idx)++;
			continue ;
		}
		if (!safe_atof(line + *idx, &coords[i], &end))
			return (printf("Error: Invalid coordinate value\n"), -1);
		*idx += end;
		i++;
		while (line[*idx] && (line[*idx] == ',' || line[*idx] == ' ' 
			|| line[*idx] == '\t'))
			(*idx)++;
	}
	if (i != 3)
		return (printf("Error: Coordinates must have 3 values (x,y,z)\n"), -1);
	vec->x = coords[0];
	vec->y = coords[1];
	vec->z = coords[2];
	return (1);
}

int	parse_normalized_vector(char *line, t_vec3 *vec, int *idx)
{
	if (parse_coordinates(line, vec, idx) == -1)
		return (-1);
	if (!validate_normalized(vec->x) || !validate_normalized(vec->y) 
		|| !validate_normalized(vec->z))
		return (-1);
	if (vec->x == 0.0 && vec->y == 0.0 && vec->z == 0.0)
		return (printf("Error: Normalized vector cannot be zero\n"), -1);
	return (1);
}
