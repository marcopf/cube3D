/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:23:50 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/09 14:40:27 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	check_side(t_game *game, int x, int y)
{
	if (x + 1 <= game->map.width - 1
		&& (game->map.map[y][x + 1] != '1' && game->map.map[y][x + 1] != ' '))
		return (0);
	if (x - 1 >= 0
		&& (game->map.map[y][x - 1] != '1' && game->map.map[y][x - 1] != ' '))
		return (0);
	if (y + 1 <= game->map.height - 1
		&& (game->map.map[y + 1][x] != '1' && game->map.map[y + 1][x] != ' '))
		return (0);
	if (y - 1 >= 0
		&& (game->map.map[y - 1][x] != '1' && game->map.map[y - 1][x] != ' '))
		return (0);
	return (1);
}

int	space_check(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == ' ' && !check_side(game, x, y))
				return (-1);
		}
	}
	return (1);
}

int	border_check(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map[++y])
	{
		if (game->map.map[y][0] != '1' && game->map.map[y][0] != ' ')
			return (-1);
		if (game->map.map[y][game->map.width - 1] != '1'
			&& game->map.map[y][game->map.width - 1] != ' ')
			return (-1);
	}
	y = -1;
	while (game->map.map[0][++y])
	{
		if (game->map.map[0][y] != '1' && game->map.map[0][y] != ' ')
			return (-1);
		else if (game->map.map[game->map.height - 1][y] != '1'
			&& game->map.map[game->map.height - 1][y] != ' ')
			return (-1);
	}
	if (space_check(game) == -1)
		return (-1);
	return (0);
}
