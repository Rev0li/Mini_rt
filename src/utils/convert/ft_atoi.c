/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:58:06 by yassine           #+#    #+#             */
/*   Updated: 2025/08/25 11:11:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

double to_double(double total, int sign, const char *str)
{
	int i;
	i = 0;

	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		total = (total * 10) + (str[i] - 48);
		i++;
	}
	while (i > 0)
	{
		total /= 10;
		i--;
	}
	return (total * sign);
}

double ft_atoi(const char *str)
{
	size_t i;
	double total;
	long sign;

	i = 0;
	total = 0;
	sign = 1;
	while (str && (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r')))
		i++;
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str && ('0' <= str[i] && str[i] <= '9'))
	{
		total = (total * 10) + (str[i] - 48);
		if ((total > INT_MAX || total < INT_MIN) && total != 2147483648)
			return (0);
		i++;
		if (str[i] && str[i] == '.' && is_digit(str[i + 1]))
			return to_double(total, sign, str + i + 1);
	}
	return (total * sign);
}
