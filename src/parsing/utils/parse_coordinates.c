/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:36:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 16:33:45 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

static int	parse_single_coord(char *line, int *idx, double *value)
{
	int	end;

	if (!is_valid_number_start(line[*idx], line[*idx + 1]))
		return (printf("Error: Invalid coordinate start\n"), -1);
	if (!safe_atof(line + *idx, value, &end))
		return (printf("Error: Invalid coordinate value\n"), -1);
	*idx += end;
	return (0);
}

int	parse_coordinates(char *line, t_vec3 *vec, int *idx)
{
	double	coords[3];
	int		i;

	i = 0;
	*idx = skip_whitespace(line, *idx);
	while (i < 3)
	{
		if (parse_single_coord(line, idx, &coords[i]) == -1)
			return (-1);
		i++;
		if (i < 3)
		{
			if (expect_comma(line, idx) == -1)
				return (-1);
		}
	}
	if (line[*idx] && !ft_isspace(line[*idx]) && line[*idx] != '\0'
		&& line[*idx] != '\n')
		return (printf("Error: Invalid character after coordinates\n"), -1);
	*vec = set_vec(coords[0], coords[1], coords[2]);
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
