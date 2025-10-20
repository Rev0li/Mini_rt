/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_part_of_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:49:50 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 19:30:25 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	skip_whitespace(char *line, int index)
{
	while (line[index] && (line[index] == ' ' || line[index] == '\t'))
		index++;
	return (index);
}

int	is_valid_char(char c)
{
	return (ft_is_digit(c) || c == ',' || c == '.' || c == '-' 
		|| c == '+' || c == ' ' || c == '\t' || c == '\n');
}

int	is_valid_number_start(char c, char next)
{
	if (ft_is_digit(c))
		return (1);
	if ((c == '-' || c == '+') && ft_is_digit(next))
		return (1);
	if (c == '.' && ft_is_digit(next))
		return (1);
	return (0);
}
