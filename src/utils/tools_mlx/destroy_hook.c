/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:15:06 by okientzl          #+#    #+#             */
/*   Updated: 2025/11/21 14:52:33 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int destroy_hook(void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	// mlx_loop_end(data->mlx);
	free_all(data);
	exit(0);
	return (0);
}
