/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:18 by bngo              #+#    #+#             */
/*   Updated: 2016/11/08 21:57:40 by bngo             ###   ########.fr       */
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
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 124)
	{

		e->zoom *= 1.2;
	}
	expose_hook(0, 0, e);
	return (0);
}

#include <stdio.h>

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 2)
	{
		e->zoom += 1.2;
		e->moveX = 1.1 * (e->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
   	 e->moveY = (e->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
		// e->var->zoom -= 1.2;
	}
	if (button == 1)
	{
		e->zoom -= 1.2;
		e->moveX = 1.1 * (e->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) - e->moveX;
   	 e->moveY = (e->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) - e->moveY;
		// e->var->zoom += 1.2;
	}
	expose_hook(x, y, e);
	return (0);
}

int			main()
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	mlx_get_params(e);
	// init_var2(e);
	e->zoom = 1;
	e->moveX = -0.5;
	e->moveY = 0;
	expose_hook(0, 0, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
