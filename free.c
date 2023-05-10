/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:35:17 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/10 11:51:13 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	free_matrix(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free (map[i]);
	free (map);
	return (1);
}

int	free_texture(t_textures *tex)
{
	if (tex->nord)
		free(tex->nord);
	tex->nord = NULL;
	if (tex->sud)
		free(tex->sud);
	tex->sud = NULL;
	if (tex->est)
		free(tex->est);
	tex->est = NULL;
	if (tex->ovest)
		free(tex->ovest);
	tex->ovest = NULL;
}

int	free_map(t_map map)
{
	if (!&map)
		return (1);
	free_matrix (&map.map);
	free (&map);
	return (1);
}

int	free_game(t_game *game)
{
	free_texture(&game->tex);
	free_map(game->map);
	return (1);
}
