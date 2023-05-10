/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:53 by marco             #+#    #+#             */
/*   Updated: 2023/05/10 09:39:49 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define NAME "cub3D"
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

typedef struct s_textures
{
	char	*nord;
	char	*sud;
	char	*ovest;
	char	*est;
	int		floor[3];
	int		ceilling[3];
}	t_textures;

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
typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_textures	tex;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_raycast	raycast;
	t_data		data;
}	t_game;

int		map_converter(t_game *game, char *path, int fd);
int		border_check(t_game *game);
int		arg_check(int argc, char **argv);
int		parse_map(t_game *game, char *path);

/*Init*/
void	init_game(t_game *game);

/*Map Parser*/
int		find_texture(t_game *game, int fd);
int		go_to_map(t_game *game, char *path);
int		get_map_line(t_game *game, char *path);
int		find_texture(t_game *game, int fd);
int		find_colors(t_game *game, int fd);
void	assign_color(t_game *game, char c, char **colors);

#endif