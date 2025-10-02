/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:58:35 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/30 13:03:02 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

unsigned int	rgb_to_hex(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

int	set_color(t_color *color, int n, int choose)
{
	if (n < 0 || n > 255)
		return (-1);
	if (choose == 1)
		color->r = n;
	else if (choose == 2)
		color->g = n;
	else
		color->b = n;
	return (1);
}

int	parse_color(char *line, t_color *color, int index)
{
	int	i;
	int	option;

	option = 1;
	i = index;
	while (line[index])
	{
		if (is_digit(line[index]))
		{
			i = index;
			while (is_digit(line[i]))
				i++;
			if (set_color(color, ft_atoi(line + index), option) == -1)
				return (-1);
			option++;
			index = i;
		}
		else
			index++;
	}
	color->hex = rgb_to_hex(color->r, color->g, color->b);
	return (1);
}
