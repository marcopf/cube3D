/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/15 11:38:04 by mpaterno         ###   ########.fr       */
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

	if (!arg_check(argc, argv))
		return (1);
	if (parse_map(&game, argv[1]) == -1)
		return (printf("Error: invalid file sintax\n"));
	init_game(&game);
	start_player(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_hook(game.mlx_win, 2, 1L<<0, input_on_press, (void *)&game);
	mlx_hook(game.mlx_win, 3, 1L<<1, input_on_release, (void *)&game);
	mlx_loop_hook(game.mlx, draw_frame, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
