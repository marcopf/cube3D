/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_n_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:20:19 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 22:21:39 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	assign_color(t_game *game, char c, char **colors)
{
	int	i;

	i = -1;
	if (c == 'F')
	{
		while (++i < 3)
			game->tex.floor[i] = ft_atoi(colors[i]);
	}
	else if (c == 'C')
	{
		while (++i < 3)
			game->tex.ceilling[i] = ft_atoi(colors[i]);
	}
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
}

int	find_colors(t_game *game, int fd)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (counter < 2 && str)
	{
		if (ft_strncmp(str, "F", 1) == 0 && ++counter)
			assign_color(game, 'F', ft_split(str + 2, ','));
		else if (ft_strncmp(str, "C", 1) == 0 && ++counter)
			assign_color(game, 'C', ft_split(str + 2, ','));
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (0);
}

int	find_texture(t_game *game, int fd)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (counter < 4 && str)
	{
		if (ft_strncmp(str, "NO", 2) == 0 && ++counter)
			game->tex.nord = ft_strdup(str + 3);
		else if (ft_strncmp(str, "SO", 2) == 0 && ++counter)
			game->tex.sud = ft_strdup(str + 3);
		else if (ft_strncmp(str, "WE", 2) == 0 && ++counter)
			game->tex.ovest = ft_strdup(str + 3);
		else if (ft_strncmp(str, "EA", 2) == 0 && ++counter)
			game->tex.est = ft_strdup(str + 3);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (0);
}
