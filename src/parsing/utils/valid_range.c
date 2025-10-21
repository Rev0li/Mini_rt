/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:13:50 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 13:04:47 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	validate_ratio(double value)
{
	if (value < 0.0 || value > 1.0)
	{
		printf("Error: Ratio must be in range [0.0, 1.0]\n");
		return (0);
	}
	return (1);
}

int	validate_normalized(double value)
{
	if (value < -1.0 || value > 1.0)
	{
		printf("Error: Normaliz vec values must be in range [-1.0, 1.0]\n");
		return (0);
	}
	return (1);
}

int	validate_fov(int value)
{
	if (value < 0 || value > 180)
	{
		printf("Error: FOV must be in range [0, 180]\n");
		return (0);
	}
	return (1);
}

int	validate_positive(double value)
{
	if (value <= 0.0)
	{
		printf("Error: Value must be positive\n");
		return (0);
	}
	return (1);
}
