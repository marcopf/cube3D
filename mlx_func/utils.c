/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:36:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/12 10:39:25 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_game *game, t_vector begin, t_vector end, int color)
{
	double	dx;
	double	dy;
	double	px;
	double	py;
	int		pixels;

	dx = end.x - (int)begin.x;
	dy = end.y - (int)begin.y;
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	px = (int)begin.x;
	py = (int)begin.y;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, px, py, color);
		px += dx;
		py += dy;
		--pixels;
	}
}

void	draw_line_on(t_data *img, t_vector begin, t_vector end, int color)
{
	double	dx;
	double	dy;
	double	px;
	double	py;
	int		pixels;

	dx = end.x - begin.x;
	dy = end.y - begin.y;
	pixels = sqrt((dx * dx) + (dy * dy)) + 1;
	dx /= pixels;
	dy /= pixels;
	px = begin.x;
	py = begin.y;
	while (pixels)
	{
		my_mlx_pixel_put(img, (int)px, (int)py, color);
		px += dx;
		py += dy;
		--pixels;
	}
}
