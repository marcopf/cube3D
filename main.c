/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 15:00:02 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!arg_check(argc, argv))
		return (1);
	map_converter(&game, argv[1]);
	if (border_check(&game) == -1)
		return (printf("Error: Invalid map\n"));
	// init_game(&game);
	// mlx_loop(game.mlx);
	return (0);
}
