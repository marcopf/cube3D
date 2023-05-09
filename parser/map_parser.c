/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:54:52 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/09 22:33:45 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	count_line(t_game *game, int fd)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	if (str)
		game->map.width = ft_strlen(str) - 1;
	while (str)
	{
		counter++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	game->map.height = counter;
	return (counter);
}

int	map_converter(t_game *game, char *path, int fd)
{
	int		y;
	int		i;
	char	*temp_gnl;

	i = 0;
	y = count_line(game, fd);
	fd = go_to_map(game, path);
	game->map.map = (char **)malloc(sizeof(char *) * (y + 1));
	temp_gnl = get_next_line(fd);
	game->map.map[i] = ft_strtrim(temp_gnl, "\n");
	free(temp_gnl);
	while (++i < y)
	{
		temp_gnl = get_next_line(fd);
		game->map.map[i] = ft_strtrim(temp_gnl, "\n");
		free(temp_gnl);
	}
	game->map.map[i] = 0;
	close(fd);
	return (0);
}

int	parse_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	find_texture(game, fd);
	find_colors(game, fd);
	close(fd);
	map_converter(game, path, go_to_map(game, path));
	if (border_check(game))
		return (-1);
	return (0);
}
