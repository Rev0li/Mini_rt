/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:15:06 by okientzl          #+#    #+#             */
/*   Updated: 2025/10/21 16:33:55 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

int	destroy_hook(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	mlx_loop_end(data->mlx);
	free_all(data);
	exit(0);
	return (0);
}
