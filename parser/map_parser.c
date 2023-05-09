/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:54:52 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/09 14:13:42 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	count_line(t_game *game, char *path)
{
	char	*str;
	int		fd;
	int		counter;

	counter = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	str = get_next_line(fd);
	if (str)
		game->map.width = ft_strlen(str) - 1;
	while (str)
	{
		counter++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	game->map.height = counter;
	return (counter);
}

int	map_converter(t_game *game, char *path)
{
	int		y;
	int		i;
	int		fd;
	char	*temp_gnl;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	i = 0;
	y = count_line(game, path);
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
