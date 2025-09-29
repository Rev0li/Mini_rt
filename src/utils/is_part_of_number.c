/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_part_of_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:49:50 by okientzl          #+#    #+#             */
/*   Updated: 2025/09/29 19:06:31 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	is_part_of_number(char current, char next)
{
	return (is_digit(current)
		|| (current == '.' && is_digit(next))
		|| current == '-');
}

int	is_valid_number_start(char current, char next)
{
	return (is_digit(current) || (current == '-' && is_digit(next)));
}
