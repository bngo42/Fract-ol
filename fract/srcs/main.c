/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:18 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 17:30:44 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_get_params(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fractol");
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
		e->moveX += (0.1);
	else if (keycode == RIGHT)
		e->moveX -= (0.1);
	else if (keycode == UP)
		e->moveY += (0.1);
	else if (keycode == DOWN)
		e->moveY -= (0.1);
	else if (keycode == HELP)
		e->freeze = (e->freeze == 0) ? 1 : 0;
	else if (keycode == SPACE)
	{
		e->zoom = 1;
		e->moveX = -0.5;
		e->moveY = 0;
		if (e->type == 0)
			e->iter = 300;
		else if (e->type == 1)
			e->iter = 18;
		else if (e->type == 2)
			e->iter = 300;
	}
	expose_hook(0, 0, e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == LMOUSE && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		e->zoom *= 1.2;
		e->moveX = 1.1 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
		e->moveY = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
	}
	if (button == RMOUSE && x > 0 && x < WIDTH && y > 0 && y < HEIGHT && e->zoom > 1.2)
	{
		e->zoom /= 1.2;
		e->moveX = 1.1 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
		e->moveY = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
	}
	expose_hook(x, y, e);
	return (0);
}

void		ft_init_env(t_env *e)
{
	e->zoom = 1;
	e->moveX = -0.5;
	e->moveY = 0;
	e->freeze = 0;
	if (e->type == 0)
	{
		e->iter = 300;
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
		ft_putendl("Allocating Thirs fractal");
}
void		ft_error(int err)
{
	if (err == -1)
		ft_putendl("Available fractal:\n- Julia\n- Mandelbrot\n- Unknow");
	else if (err == -2)
		ft_putendl("Too many arguments.");
	else if (err == -3)
		ft_putendl("Err3");
	else if (err == -4)
		ft_putendl("Err4");
	else if (err == -5)
		ft_putendl("Err5");
	exit(0);
}

#include <stdio.h>

int			mouse_motion(int x, int y, t_env *e)
{
	int dirx;
	int diry;

	dirx = e->mousex - x;
	diry = e->mousey - y;
	e->mousex = x;
	e->mousey = y;
	//if (!e->freeze && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	if (!e->freeze)
	{
		e->j->cre += (dirx > 0) ? -(double)0.0200 : ((double)0.0200);
		e->j->cim += (diry > 0) ? -(double)0.0200 : ((double)0.0200);
		expose_hook(0, 0, e);
		//printf("Mouse position: x: %i Y: %i\n", x, y);
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
	{
		e->type = 1;
	}
	else if (ft_strcmp(argv[1], "Unknow") == 0)
		e->type = 2;
	else
		ft_error(-1);
	ft_init_env(e);
	mlx_get_params(e);
	expose_hook(0, 0, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	if (e->type == 0)
		mlx_hook(e->win, 6, 0, mouse_motion, e);
	mlx_loop(e->mlx);
	return (0);
}
