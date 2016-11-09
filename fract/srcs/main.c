/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:18 by bngo              #+#    #+#             */
/*   Updated: 2016/11/09 18:06:58 by bngo             ###   ########.fr       */
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
	else if (keycode == LEFT)
		e->moveX += (1.2);
	else if (keycode == RIGHT)
		e->moveX -= (1.2);
	expose_hook(0, 0, e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == RMOUSE)
	{
		e->zoom *= 1.2;
		e->moveX = 1.1 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
		e->moveY = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
	}
	if (button == LMOUSE && e->zoom > 1.2)
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

int			main(int argc, char **argv)
{
	t_env *e;

	e = NULL;
	(void)argc;
	(void)argv;
	if (argc <= 1 || argc > 2)
		ft_error((argc <= 1) ? -1 : -2);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (ft_strcmp(argv[1], "Julia") == 0)
		e->type = 0;
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		e->type = 1;
	else if (ft_strcmp(argv[1], "Unknow") == 0)
		e->type = 2;
	else
		ft_error(-1);
	ft_init_env(e);
	mlx_get_params(e);
	expose_hook(0, 0, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
