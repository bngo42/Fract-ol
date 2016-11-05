/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:54:20 by bngo              #+#    #+#             */
/*   Updated: 2016/11/05 15:58:56 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_set_fract(int type)
{
	t_fract *info;

	if(!(info = (t_fract*)malloc(sizeof(t_fract))))
		ft_error(-2);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fract'ol");
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->size = 10;
	info->zoom = 0;
	if (type == 1)
		ft_draw_julia(info);
	else if (type == 2)
		ft_draw_mandelbrot(info, info->size);
	else if (type == 3)
		ft_draw_unknow(info);
	mlx_hook(info->win, 2, 1L << 1, key_event, info);
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
