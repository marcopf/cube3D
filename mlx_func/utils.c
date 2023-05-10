/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:36:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/10 09:41:09 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_game *env, float x0, float y0, float x, float y)
{
	int		pixels;
	double	pixelx;
	double	pixely;
	double	dx;
	double	dy;

	dx = x -x0;
	dy = y - y0;
	pixels = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	dx /= pixels;
	dy /= pixels;
	pixelx = x0;
	pixely = y0;
	while (pixels)
	{
		my_mlx_pixel_put(&env->data, pixelx, pixely, 0x00FF0000);
		pixelx += dx;
		pixely += dy;
		--pixels;
	}
}
