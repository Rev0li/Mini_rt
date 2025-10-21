/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_chars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:58:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 14:41:47 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	expect_comma(char *line, int *index)
{
	if (line[*index] != ',')
		return (printf("Error: Missing comma between RGB values\n"), -1);
	(*index)++;
	return (0);
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

int	is_valid_identifier_char(char c)
{
	return (c == 'A' || c == 'C' || c == 'L' || c == 's'
		|| c == 'p' || c == 'c' || c == 'y' || c == 'l');
}

int	validate_line_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	while (line[i] && is_valid_identifier_char(line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_char(line[i]))
		{
			printf("Error: Invalid character '%c' at position %d\n",
				line[i], i);
			return (-1);
		}
		i++;
	}
	return (1);
}
