/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/08 22:35:23 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

float pa = 0;

int	close_p()
{
	exit(0);
}

char *map[] = { "11111111111111111111",
				"10000000100000000001",
				"10000000100000000001",
				"10000000111110000001",
				"10000000100000000001",
				"10000000100000000001",
				"10000000100000000001",
				"10000000000000000001",
				"10000000000000000001",
				"10000000000001111111",
				"10000000000000000001",
				"10000011111000000001",
				"10000000111000000001",
				"11111111111111111111"};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_env *env, float off_x, float off_y, int color)
{
	int x, y = -1;

	while (++y < 30)
	{
		x = -1;
		while (++x < 30)
			my_mlx_pixel_put(&env->data, off_x + x, off_y + y, color);
	}
}

void	draw_line(t_env *env, float x0, float y0, float x, float y)
{
	int pixels;
	double pixelx, pixely;
	double	dx, dy;

	dx = x -x0;
	dy = y - y0;
	pixels = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	dx /= pixels;
	dy /= pixels;
	pixelx = x0;
	pixely = y0;
	while (pixels)
	{
		my_mlx_pixel_put(&env->data, pixelx, pixely, 0x00FF0000);
		// if ((int)pixelx % 31 == 0)
		// 	draw_pixel(env, pixelx, pixely, 0x0000FF00);
		// if ((int)pixely % 31 == 0)
		// 	draw_pixel(env, pixelx, pixely, 0x000000FF);
		pixelx += dx;
		pixely += dy;
		--pixels;
	}
}

void tester(t_env *env, float x, float y, float pdx, float pdy)
{
	//which box of the map we're in
    int mapX = (int)(x / 31.0);
    int mapY = (int)(y / 31.0);
	float rayDirX = x + pdx;
	float rayDirY = y + pdy;

      //length of ray from current position to next x or y-side
    double sideDistX;
    double sideDistY;

       //length of ray from one x or y-side to next x or y-side
    double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
    double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
    int stepX;
    int stepY;

    int hit = 0; //was there a wall hit?
    int side; //was a NS or a EW wall hit?
	if (rayDirX < 0)
    {
    	stepX = -1;
        sideDistX = (x - mapX) * deltaDistX;
    }
    else
    {
      stepX = 1;
      sideDistX = (mapX + 1.0 - x) * deltaDistX;
    }
    if (rayDirY < 0)
    {
      stepY = -1;
      sideDistY = (y - mapY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (mapY + 1.0 - y) * deltaDistY;
    }
	int i = -1;
	while (hit == 0)
    {
      //jump to next map square, either in x-direction, or in y-direction
      if (sideDistX < sideDistY)
      {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
      }
      else
      {
        sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
		if (map[mapY][mapX] == '1')
			hit = 1;
    } 
	draw_line(env, x, y, (mapX * 31), (mapY * 31));
	//draw_line(env, x, y, x + 31 * pdx, y + 31 * pdy);
}


void	draw_player(t_env *env, float off_x, float off_y, int color)
{
	int x, y = -1;

	while (++y < 15)
	{
		x = -1;
		while (++x < 15)
			my_mlx_pixel_put(&env->data, off_x + x, off_y + y, color);
	}
}

void	draw_dir(t_env *env, float off_x, float off_y, int color)
{
	int x, y = -1;

	while (++y < 5)
	{
		x = -1;
		while (++x < 5)
			my_mlx_pixel_put(&env->data, off_x + x, off_y + y, color);
	}
}

void	env_init(t_env *env)
{
	env->width = 621;
	env->height = 435;
}

//(MAC M1 KEY)
//13 == w
//0 == a
//s == 1
//d == 2
//esc == 53

void	draw_background(t_env *env)
{
	int x, y = -1;

	while (++y < 14)
	{
		x = -1;
		while (++x < 20)
		{
			if (map[y][x] == '1')
				draw_pixel(env, x * 31, y * 31, 0x00FFFFFF);
			else
				draw_pixel(env, x * 31, y * 31, 0x00565656);
		}
	}
}

void	draw_rays(t_env *env, float x, float y)
{
	float pdx, pdy, fov = -0.66;

	while (fov < 0.66)
	{
		pdy = sin(pa + fov) * 10;
		pdx = cos(pa + fov) * 10;
		//draw_line(env, x, y, x + pdx *20, y + pdy *20);
		tester(env, x + 7.5, y + 7.5, pdx, pdy);
		fov += 0.05;
	}
}

int	key(int keycode, t_env *env)
{
	static float x = 100, y = 100, pdx = 0, pdy = 0;

	if (keycode == 0)
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (keycode == 13)
	{
		y += pdy;
		x += pdx;
	}
	if (keycode == 2)
	{
		pa += 0.1;
		if (pa > 2 * PI)
			pa -= 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (keycode == 1)
	{
		y -= pdy;
		x -= pdx;
	}
	env->data.img = mlx_new_image(env->mlx, env->width, env->height);
	env->data.addr = mlx_get_data_addr(env->data.img, &env->data.bits_per_pixel,
			&env->data.line_length, &env->data.endian);
	draw_background(env);
	// pdy = sin(pa - 0.66) * 5;
	// pdx = cos(pa - 0.66) * 5;
	// draw_line(env, x + 7.5, y + 7.5, x + pdx * 23, y + pdy * 23);
	// pdy = sin(pa + 0.66) * 5;
	// pdx = cos(pa + 0.66) * 5;
	// draw_line(env, x + 7.5, y + 7.5, x + pdx * 23, y + pdy * 23);
	draw_rays(env, x, y);
	draw_player(env, x, y, 0x00FFFFFF);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->data.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env_init(&env);
	env.mlx_win = mlx_new_window(env.mlx, env.width, env.height, "Hello world!");
	mlx_hook(env.mlx_win, 2, 0, key, (void *)&env);
	mlx_hook(env.mlx_win, 17, 0, close_p, 0);
	mlx_loop(env.mlx);
}
