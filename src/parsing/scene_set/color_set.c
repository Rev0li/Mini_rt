/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:58:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:22:39 by okientzl         ###   ########.fr       */
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

int	parse_color(char *line, t_color *color, int index)
{
	int	rgb[3];
	int	i;
	int	end;

	i = 0;
	index = skip_whitespace(line, index);
	while (i < 3 && line[index])
	{
		if (!ft_is_digit(line[index]) && line[index] != '-' && line[index] != '+')
		{
			index++;
			continue ;
		}
		if (!safe_atoi(line + index, &rgb[i], &end))
			return (printf("Error: Invalid color value\n"), -1);
		if (!validate_color(rgb[i]))
			return (-1);
		index += end;
		i++;
		while (line[index] && (line[index] == ',' || line[index] == ' ' 
			|| line[index] == '\t'))
			index++;
	}
	if (i != 3)
		return (printf("Error: Color must have 3 RGB values\n"), -1);
	color->r = rgb[0];
	color->g = rgb[1];
	color->b = rgb[2];
	color->hex = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	return (1);
}
