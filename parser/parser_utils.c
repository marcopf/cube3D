/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:26:29 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 22:27:12 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	get_map_line(t_game *game, char *path)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (0);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		i++;
		if (str[0] == ' ' || ft_isdigit(str[0]))
		{
			free(str);
			close(fd);
			return (i);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	go_to_map(t_game *game, char *path)
{
	int		line;
	int		i;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	i = -1;
	line = get_map_line(game, path);
	while (++i < line - 1)
	{
		str = get_next_line(fd);
		free(str);
	}
	return (fd);
}

int	arg_check(int argc, char **argv)
{
	int	i;

	if (argc < 2 || argc > 2)
		return (printf ("Numero argomenti sbagliato\n") * 0);
	i = ft_strlen (argv[1]) - 4;
	if (i < 0)
		return (printf ("Estensione file errata\n") * 0);
	if (ft_strncmp(argv[1] + i, ".cub", 4))
		return (printf ("Estensione file errata\n") * 0);
	return (1);
}
