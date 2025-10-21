/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:22:19 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 15:39:58 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

static int	parse_float_sign(char *str, int *i, int *sign)
{
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (1);
}

static int	parse_float_integer(char *str, int *i, double *result)
{
	int	has_digits;

	has_digits = 0;
	while (ft_is_digit(str[*i]))
	{
		*result = *result * 10.0 + (str[*i] - '0');
		(*i)++;
		has_digits = 1;
	}
	return (has_digits);
}

static int	parse_float_decimal(char *str, int *i, double *result)
{
	double	divisor;
	int		has_digits;

	has_digits = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		divisor = 10.0;
		if (!ft_is_digit(str[*i]))
			return (-1);
		while (ft_is_digit(str[*i]))
		{
			*result += (str[*i] - '0') / divisor;
			divisor *= 10.0;
			(*i)++;
			has_digits = 1;
		}
	}
	return (has_digits);
}

int	safe_atof(char *str, double *result, int *end_index)
{
	int		i;
	int		sign;
	double	value;
	int		has_int;
	int		has_dec;

	i = 0;
	value = 0.0;
	if (!str || !result)
		return (0);
	parse_float_sign(str, &i, &sign);
	has_int = parse_float_integer(str, &i, &value);
	has_dec = parse_float_decimal(str, &i, &value);
	if ((!has_int && !has_dec) || has_dec == -1)
		return (0);
	if (str[i] == '.')
		return (0);
	*result = value * sign;
	if (end_index)
		*end_index = i;
	return (1);
}

int	safe_atoi(char *str, int *result, int *end_index)
{
	double	temp;
	int		end;

	if (!safe_atof(str, &temp, &end))
		return (0);
	if (temp != (int)temp)
		return (0);
	if (temp < INT_MIN || temp > INT_MAX)
		return (0);
	*result = (int)temp;
	if (end_index)
		*end_index = end;
	return (1);
}
