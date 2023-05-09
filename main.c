/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 14:27:05 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	arg_check(int argc, char **argv)
{
	int	i;

	i = ft_strlen (argv[1]) - 4;
    if (argc < 2 || argc > 2)
		return (printf ("Numero argomenti sbagliato\n"));
	if (!ft_strncmp(argv[1][i], ".cub", 4))
		return (printf ("Estensione file errata\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!arg_check(argc, argv))
		return (1);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
