/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:41 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/12 13:18:36 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

/*void	init_wall_tex(t_game *game)
{
	game->walls[0].img = mlx_xpm_file_to_image(game->mlx,
			"../pictures/img/wall_0.xpm", &(game->wall_height[0]), &(game->wall_width[0]));
	game->walls[1].img = mlx_xpm_file_to_image(game->mlx,
			"../pictures/img/wall_1.xpm", &(game->wall_height[1]), &(game->wall_width[1]));
	game->walls[2].img = mlx_xpm_file_to_image(game->mlx,
			"../pictures/img/wall_2.xpm", &(game->wall_height[2]), &(game->wall_width[2]));
	game->walls[3].img = mlx_xpm_file_to_image(game->mlx,
			"../pictures/img/wall_3.xpm", &(game->wall_height[3]), &(game->wall_width[3]));
	game->walls[0].addr = mlx_get_data_addr(game->walls[0].img,
			&game->walls[0].bits_per_pixel, &game->walls[0].line_length,
			&game->walls[0].endian);
	game->walls[1].addr = mlx_get_data_addr(game->walls[1].img,
			&game->walls[1].bits_per_pixel, &game->walls[1].line_length,
			&game->walls[1].endian);
	game->walls[2].addr = mlx_get_data_addr(game->walls[2].img,
			&game->walls[2].bits_per_pixel, &game->walls[2].line_length,
			&game->walls[2].endian);
	game->walls[3].addr = mlx_get_data_addr(game->walls[3].img,
			&game->walls[3].bits_per_pixel, &game->walls[3].line_length,
			&game->walls[3].endian);
}*/

// void	init_minimap(t_game *game)
// {
// 	game->minimap.width = game->map.width;
// 	game->minimap.height = game->map.height;
// 	game->minimap.x = WIDTH - game->minimap.width;
// 	game->minimap.y = 1;
// 	game->minimap.map.img = mlx_new_image(game->mlx, game->minimap.width,
// 			game->minimap.height);
// 	game->minimap.map.addr = mlx_get_data_addr(game->minimap.map.img,
// 			&game->minimap.map.bits_per_pixel, &game->minimap.map.line_length,
// 			&game->minimap.map.endian);
// }

void	init_tex(t_textures *tex)
{
	tex->nord = 0;
	tex->sud = 0;
	tex->ovest = 0;
	tex->est = 0;
}

void	init_game(t_game *game)
{	
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window (game->mlx, WIDTH, HEIGHT, NAME);
	game->data.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel, &game->data.line_length,
			&game->data.endian);
	init_tex(&game->tex);
	//init_wall_tex(game);
}
