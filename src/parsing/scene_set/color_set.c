/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:58:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 14:39:43 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

unsigned int	rgb_to_hex(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

int	validate_color(int value)
{
	if (value < 0 || value > 255)
	{
		printf("Error: RGB values must be in range [0, 255]\n");
		return (0);
	}
	return (1);
}

static int	parse_single_color(char *line, int *index, int *value)
{
	int	end;

	if (!ft_is_digit(line[*index]))
		return (printf("Error: Color value must be [int,int,int]\n"), -1);
	if (!safe_atoi(line + *index, value, &end))
		return (printf("Error: Invalid color value\n"), -1);
	if (!validate_color(*value))
		return (-1);
	*index += end;
	return (0);
}

int	parse_color(char *line, t_color *color, int index)
{
	int	rgb[3];
	int	i;

	i = 0;
	index = skip_whitespace(line, index);
	while (i < 3)
	{
		if (parse_single_color(line, &index, &rgb[i]) == -1)
			return (-1);
		if (i < 2 && expect_comma(line, &index) == -1)
			return (-1);
		i++;
	}
	index = skip_whitespace(line, index);
	if (line[index] && line[index] != '\0' && line[index] != '\n')
		return (printf("Error: Extra characters after RGB values\n"), -1);
	color->r = rgb[0];
	color->g = rgb[1];
	color->b = rgb[2];
	color->hex = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	return (1);
}
