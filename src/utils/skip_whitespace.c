/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:49:50 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 16:36:27 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	skip_whitespace(char *line, int index)
{
	while (line[index] && (line[index] == ' '
			|| line[index] == '\t'
			|| line[index] == '\n'
			|| line[index] == '\v'
			|| line[index] == '\f'
			|| line[index] == '\r'))
		index++;
	return (index);
}
