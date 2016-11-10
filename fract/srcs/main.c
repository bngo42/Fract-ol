/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:18 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 21:24:12 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_hook2(int keycode, t_env *e)
{
	if (keycode == HELP)
		e->freeze = (e->freeze == 0) ? 1 : 0;
	else if (keycode == SPACE)
	{
		e->zoom = 1;
		e->mvx = -0.5;
		e->mvy = 0;
		if (e->type == 0)
			e->iter = 150;
		else if (e->type == 1)
			e->iter = 18;
		else if (e->type == 2)
			e->iter = 300;
	}
	else if (keycode == NEXT)
	{
		e->type++;
		if (e->type == 3)
			e->type = 0;
	}
	else if (keycode == PREV)
	{
		e->type--;
		if (e->type == -1)
			e->type = 2;
	}

}


int			key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	else if (keycode == PAGEUP)
		e->iter *= 1.2;
	else if (keycode == PAGEDN && e->iter > 5)
		e->iter /= 1.2;
	else if (keycode == LEFT)
		e->mvx += (0.01 / e->zoom);
	else if (keycode == RIGHT)
		e->mvx -= (0.01 / e->zoom);
	else if (keycode == UP)
		e->mvy += (0.01 / e->zoom);
	else if (keycode == DOWN)
		e->mvy -= (0.01 / e->zoom);
	else
		key_hook2(keycode, e);
	expose_hook(0, 0, e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == LMOUSE && x > 0 && x < W && y > 0 && y < H)
	{
		e->zoom *= 1.2;
		e->mvx = 1.1 * (x - W / 2) / (0.5 * e->zoom * W) + e->mvx;
		e->mvy = (y - H / 2) / (0.5 * e->zoom * H) + e->mvy;
	}
	if (button == RMOUSE && x > 0 && x < W && y > 0 && y < H && e->zoom > 1.2)
	{
		e->zoom /= 1.2;
		e->mvx = 1.1 * (x - W / 2) / (0.5 * e->zoom * W) + e->mvx;
		e->mvy = (y - H / 2) / (0.5 * e->zoom * H) + e->mvy;
	}
	expose_hook(x, y, e);
	return (0);
}

void		ft_init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W, H, "fractol");
	e->zoom = 1;
	e->mvx = -0.5;
	e->mvy = 0;
	e->freeze = 0;
	if (e->type == 0)
	{
		e->iter = 150;
		e->j = (t_jul*)malloc(sizeof(t_jul));
		e->j->cre = -0.7;
		e->j->cim = 0.27015;
	}
	else if (e->type == 1)
	{
		e->iter = 60;
		init_var3(e);
		e->m = (t_mandel*)malloc(sizeof(t_mandel));
	}
	else if (e->type == 2)
	{
		e->iter = 60;
		init_var3(e);
		e->m = (t_mandel*)malloc(sizeof(t_mandel));
	}
}

void		ft_error(int err)
{
	if (err == -1)
		ft_putendl("Available fractal:\n- Julia\n- Mandelbrot\n- Unknow");
	else if (err == -2)
		ft_putendl("Too many arguments.");
	exit(0);
}

int			mouse_motion(int x, int y, t_env *e)
{
	int dirx;
	int diry;

	dirx = e->mousex - x;
	diry = e->mousey - y;
	e->mousex = x;
	e->mousey = y;
	if (!e->freeze && x > 0 && y > 0 && x < W && y < H)
	{
		e->j->cre = (double)x / (double)W * 4 - 2;
		e->j->cim = (double)y / (double)H * 4 - 2;
		expose_hook(0, 0, e);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_env *e;

	e = NULL;
	if (argc <= 1 || argc > 2)
		ft_error((argc <= 1) ? -1 : -2);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (ft_strcmp(argv[1], "Julia") == 0)
		e->type = 0;
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		e->type = 1;
	else if (ft_strcmp(argv[1], "Mandelbar") == 0)
		e->type = 2;
	else
		ft_error(-1);
	ft_init_env(e);
	expose_hook(0, 0, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	if (e->type == 0)
		mlx_hook(e->win, 6, 0, mouse_motion, e);
	mlx_loop(e->mlx);
	return (0);
}
