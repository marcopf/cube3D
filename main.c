/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/10 11:01:35 by mpaterno         ###   ########.fr       */
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
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
