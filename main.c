/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 22:30:43 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	free(game->tex.est);
	free(game->tex.nord);
	free(game->tex.sud);
	free(game->tex.ovest);
	while (game->map.map[++i])
		free(game->map.map[i]);
	free(game->map.map);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i = -1;

	if (!arg_check(argc, argv))
		return (1);
	if (parse_map(&game, argv[1]) == -1)
		printf("Error: invalid file sintax\n");
	free_game(&game);
	// map_converter(&game, argv[1]);
	// if (border_check(&game) == -1)
	// 	return (printf("Error: Invalid map\n"));
	// // init_game(&game);
	// // mlx_loop(game.mlx);
	// game.mlx = mlx_init();
	// game.mlx_win = mlx_new_window(game.mlx, 640, 350, "Hello world!");
	// mlx_loop(game.mlx);
	return (0);
}
