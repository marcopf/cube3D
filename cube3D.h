/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:53 by marco             #+#    #+#             */
/*   Updated: 2023/05/09 14:25:00 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define NAME "cub3D"
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_raycast	raycast;
	t_image		image;
	t_image		screen;
}	t_game;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_map
{
	t_vector	player_pos;
	char		**map;
	int			width;
	int			height;
}	t_map;

typedef struct s_raycast
{
	t_vector	draw_start;
	t_vector	draw_end;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	ray_dir;
	double		perpwalldist;
	int			line_height;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
}	t_raycast;

typedef struct s_minimap
{
	t_image		map;
	int			x;
	int			y;
	int			width;
	int			height;
	t_vector	begin_ray;
	t_vector	end_ray;
}	t_minimap;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	double		rot_dir;
}	t_player;

/*Init*/
void	init_game(t_game *game);

#endif