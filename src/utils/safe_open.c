/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:09:17 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/20 18:45:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	safe_open(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error Open \n");
		return (-1);
	}
	return (0);
}
