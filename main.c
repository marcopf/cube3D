/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 14:00:56 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	// game.mlx = mlx_init();
	// game.mlx_win = mlx_new_window(game.mlx, 640, 350, "Hello world!");
	map_converter(&game, argv[1]);
	printf("%d\n",border_check(&game));
	// while (game.map.map[++i])
	// 	free(game.map.map[i]);
	// free(game.map.map);
	// mlx_loop(game.mlx);
}
