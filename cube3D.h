/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:53 by marco             #+#    #+#             */
/*   Updated: 2023/05/12 11:36:01 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define RGB_RED 0x00FF0000
# define RGB_GREEN 0x0000FF00
# define RGB_BLUE 0x000000FF
# define RGB_YELLOW 0x00FFFF00
# define RGB_WHITE 0x00FFFFFF
# define RGB_DARK_GREY 0x00282828

# define NAME "cub3D"
# define PLAYER_CHARACTERS "NSWE"
# define WIDTH 1280
# define HEIGHT 720
# define SPEED 3.0
# define ROT_SPEED 2.5
# define TEXTURE_SIZE 64
# define TILE_SET 10

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
	double		perp_wall_dist;
	double		camera_x;
	int			side;
	int			hit;
	int			line_height;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			color;
}	t_raycast;

typedef struct s_minimap
{
	t_data		map;
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
	t_vector	mov_dir;
	t_vector	plane;
	t_vector	mov_speed;
	double		rot_speed;
	double		rot_dir;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	double		frame_time;
	int			wall_width[13];
	int			wall_height[13];
	t_textures	tex;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_raycast	ray;
	t_data		data;
	t_data		walls[13];
	t_data		screen;
}	t_game;

int		map_converter(t_game *game, char *path, int fd);
int		border_check(t_game *game);
int		arg_check(int argc, char **argv);
int		parse_map(t_game *game, char *path);
int		free_game(t_game *game);

/*Movement*/
void	update_inputs(t_game *game);
int		input_on_press(int key, t_game *game);
int		input_on_release(int key, t_game *game);

/*drawing*/
void	raycaster_flat(t_game *game);
int		draw_frame(t_game *game);
void	draw_line_on(t_data *img, t_vector begin, t_vector end, int color);
void	draw_line(t_game *game, t_vector begin, t_vector end, int color);

/*Init*/
void	init_game(t_game *game);
int		start_player(t_game *game);

/*Map Parser*/
int		find_texture(t_game *game, int fd);
int		go_to_map(t_game *game, char *path);
int		get_map_line(t_game *game, char *path);
int		find_texture(t_game *game, int fd);
int		find_colors(t_game *game, int fd);
int		assign_color(t_game *game, char c, char **colors);

#endif