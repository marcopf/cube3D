/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:51:03 by mpaterno          #+#    #+#             */
/*   Updated: 2023/05/12 15:18:44 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	col_cycle(t_game *game, int *col, char **colors)
{
	int	val;
	int	i;

	i = -1;
	while (++i < 3)
	{
		val = ft_atoi(colors[i]);
		if (val > 255 || (val == 0 && colors[i][0] != '0'))
			return (-1);
		col[i] = val;
	}
	return (0);
}

int	assign_color(t_game *game, char c, char **colors)
{
	int	i;
	int	val;

	i = -1;
	if (c == 'C')
	{
		if (col_cycle(game, game->tex.ceilling, colors) == -1)
			return (-1);
	}
	else if (c == 'F')
	{
		if (col_cycle(game, game->tex.floor, colors) == -1)
			return (-1);
	}
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
	return (0);
}

int	find_colors(t_game *game, int fd)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	while (counter < 2 && str)
	{
		if (ft_strncmp(str, "F", 1) == 0 && ++counter)
		{
			if (assign_color(game, 'F', ft_split(str + 2, ',')))
				return (-1);
		}
		else if (ft_strncmp(str, "C", 1) == 0 && ++counter)
		{
			if (assign_color(game, 'C', ft_split(str + 2, ',')))
				return (-1);
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	if (counter < 2)
		return (-1);
	return (0);
}
