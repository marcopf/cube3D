/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:41 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/09 14:26:22 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_minimap(t_game *game)
{
	game->minimap.width = game->map.width;
	game->minimap.height = game->map.height;
	game->minimap.x = WIDTH - game->minimap.width;
	game->minimap.y = 1;
	game->minimap.map.img = mlx_new_image(game->mlx, game->minimap.width,
			game->minimap.height);
	game->minimap.map.addr = mlx_get_data_addr(game->minimap.map.img,
			&game->minimap.map.bits_per_pixel, &game->minimap.map.line_length,
			&game->minimap.map.endian);
}

void	init_game(t_game *game)
{	
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window (game->mlx, WIDTH, HEIGHT, NAME);
	game->screen.img = mlx_new_image (game->mlx, WIDTH, HEIGHT);
	game->screen.addr = mlx_get_data_addr (game->screen.img,
			game->screen.bits_per_pixel, game->screen.line_length,
			game->screen.endian);
	init_minimap(game);
}
