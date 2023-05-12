/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:18:59 by marco             #+#    #+#             */
/*   Updated: 2023/05/12 21:20:31 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	input_on_press(int key, t_game *game)
{
	if (key == 0)
		game->player.mov_dir.y = -1;
	else if (key == 1)
		game->player.mov_dir.x = 1;
	else if (key == 2)
		game->player.mov_dir.y = 1;
	else if (key == 13)
		game->player.mov_dir.x = -1;
	else if (key == 123)
		game->player.rot_dir = -1;
	else if (key == 124)
		game->player.rot_dir = 1;
	else if (key == 53)
		free_game(game);
	return (0);
}

int	input_on_release(int key, t_game *game)
{
	if (key == 13 || key == 1)
		game->player.mov_dir.x = 0;
	else if (key == 0 || key == 2)
		game->player.mov_dir.y = 0;
	else if (key == 123 || key == 124)
		game->player.rot_dir = 0;
	return (0);
}
