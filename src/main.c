/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:54:20 by bngo              #+#    #+#             */
/*   Updated: 2016/11/07 17:20:10 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fract		*ft_init_fract(int type)
{
	t_fract *info;

	if (!(info = (t_fract*)malloc(sizeof(t_fract))))
		ft_error(-2);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fract'ol");
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->type = type;
	info->size = 10;
	info->zoom = 1;
	info->midX = 0;
	info->midY = 0;
	return (info);
}

void		ft_set_fract(int type)
{
	t_fract *info;

	info = ft_init_fract(type);
	ft_draw_image(info);
	mlx_hook(info->win, 2, 1L << 1, key_event, info);
	mlx_mouse_hook(info->win, mouse_event, info);
	mlx_loop(info->mlx);
}

void		ft_error(int err)
{
	if (err == -1)
		ft_putendl("Available fractal:\n- Julia\n- Mandelbrot\n- Unknow");
	else if (err == -2)
		ft_putendl("Err2");
	else if (err == -3)
		ft_putendl("Err3");
	else if (err == -4)
		ft_putendl("Err4");
	else if (err == -5)
		ft_putendl("Err5");
	exit(0);
}

int				main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc <= 1)
		ft_error(-1);
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_strcmp(argv[i], "Julia") == 0)
				ft_set_fract(1);
			else if (ft_strcmp(argv[i], "Mandelbrot") == 0)
				ft_set_fract(2);
			else if (ft_strcmp(argv[i], "Unknow") == 0)
				ft_set_fract(3);
			else
				ft_error(-1);
		}
	}
	return (0);
}
