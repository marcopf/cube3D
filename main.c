/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:28 by marco             #+#    #+#             */
/*   Updated: 2023/05/08 09:05:24 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

float pa = 0;
int	map[] = {1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 1, 0, 0, 0, 1,
			1, 0, 0, 1, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 1, 0, 0, 0, 1,
			1, 0, 0, 1, 0, 0, 0, 1,
			1, 0, 0, 1, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_env *env, float x0, float y0, float x, float y)
{
	int pixels;
	double	dx, dy;

	dx = x -x0;
	dy = y - x0;
	pixels = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	dx /= pixels;
	dy /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(&env->data, x0, y0, 0x0000FFFF);
		x0 += dx;
		y0 += dy;
		pixels--;
	}
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

// void	draw_rays(t_env *env, float px, float py)
// {
// 	float xo, yo, rx, ry, ra, aTan;
// 	int	my, mx, mp, dof, r;
	
// 	ra = pa;
// 	dof = 0;
// 	aTan = -1/tan(ra);
// 	if (ra > PI)
// 	{
// 		ry = (((int)py >> 6) << 6) - 0.0001;
// 		rx = (py - ry) * aTan + px;
// 		yo = -64;
// 		xo = yo * aTan;
// 	}
// 		if (ra < PI)
// 	{
// 		ry = (((int)py >> 6) << 6) + 64;
// 		rx = (py - ry) * aTan + px;
// 		yo = 64;
// 		xo = yo * aTan;
// 	}
// 	if (ra == 0 || ra == PI)
// 	{
// 		rx = px;
// 		ry = py;
// 		dof = 8;
// 	}
// 	printf("%d\n", dof);
// 	while (dof < 8)
// 	{
// 		mx = (int) (rx) >> 6;
// 		my = (int) (ry) >> 6;
// 		mp = (my * 8) + mx;
// 		if (mp < 64 && map[mp] == 1)
// 			dof = 8;
// 		else
// 		{
// 			rx += xo;
// 			ry += yo;
// 			dof += 1;
// 		}
// 	}
// 	draw_line(env, rx, ry, xo, yo);
// }

void	env_init(t_env *env)
{
	env->width = 620;
	env->height = 430;
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

	while (++y < 8)
	{
		x = -1;
		while (++x < 8)
		{
			if (map[(y * 8) + x] == 1)
				draw_pixel(env, x * 31, y * 31, 0x00FFFFFF);
			else
				draw_pixel(env, x * 31, y * 31, 0x00565656);
		}
	}
}

void	key(int keycode, t_env *env)
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
		y -= pdy;
		x -= pdx;
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
		y += pdy;
		x += pdx;
	}
	env->data.img = mlx_new_image(env->mlx, env->width, env->height);
	env->data.addr = mlx_get_data_addr(env->data.img, &env->data.bits_per_pixel,
			&env->data.line_length, &env->data.endian);
	draw_background(env);
	draw_dir(env, x + pdx * 5 + 7, y + pdy * 5 + 7, 0x0000FFFF);
	draw_player(env, x, y, 0x00FFFFFF);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->data.img, 0, 0);
}

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env_init(&env);
	env.mlx_win = mlx_new_window(env.mlx, env.width, env.height, "Hello world!");
	mlx_hook(env.mlx_win, 2, 0, key, (void *)&env);
	mlx_hook(env.mlx_win, 17, 0, exit, 0);
	mlx_loop(env.mlx);
}
