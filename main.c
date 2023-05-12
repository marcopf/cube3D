/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/12 10:48:17 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (!arg_check(argc, argv))
		return (1);
	if (parse_map(&game, argv[1]) == -1)
		return (printf("Error: invalid file sintax\n"));
	start_player(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_hook(game.mlx_win, 2, 0, input_on_press, (void *)&game);
	mlx_hook(game.mlx_win, 3, 0, input_on_release, (void *)&game);
	mlx_loop_hook(game.mlx, draw_frame, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
