/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:01:28 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/20 15:50:21 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

// Dans src/display/draw.c
void put_pixel(t_mlx *data, int x, int y, int color)
{
    if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return;
    
	int offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)(data->addr + offset) = color;

}

void draw(t_mlx *data)
{
    // Dessiner un carré rouge en bas à droite
    int size = 50;
    int red = 0x00FF0000;
	int	blue = 0x00AAFF;
    for (int y = W_HEIGHT - size; y < W_HEIGHT; y++)
	{
        for (int x = W_WIDTH - size; x < W_WIDTH; x++)
		{
			if (y == W_HEIGHT - size || y == W_HEIGHT - 1 || x == W_WIDTH - size || x == W_WIDTH - 1)
            	put_pixel(data, x, y, red);
			else
				put_pixel(data, x, y, blue);
        }
    }
    refresh_image(data);
}

/*typedef struct s_mlx*/
/*{*/
/*	void	*mlx;*/
/*	void	*window;*/
/*	void	*img;*/
/*	char	*addr;*/
/*	int		bits_per_pixel;*/
/*	int		line_length;*/
/*	int		endian;*/
/*}	t_mlx;*/
