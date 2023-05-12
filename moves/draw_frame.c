/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:30:32 by marco             #+#    #+#             */
/*   Updated: 2023/05/12 11:41:25 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	draw_background(t_game *game)
{
	t_vector	begin;
	t_vector	end;
	int			y;

	begin.x = 0;
	end.x = WIDTH;
	y = -1;
	while (++y < (HEIGHT / 2))
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->data, begin, end, 0x00000000);
	}
	y -= 1;
	while (++y < HEIGHT)
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->data, begin, end, 0x00000000);
	}
}

int	draw_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	draw_background(game);
	raycaster_flat(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->data.img, 0, 0);
	update_inputs(game);
	return (0);
}
