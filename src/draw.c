/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:44:34 by bngo              #+#    #+#             */
/*   Updated: 2016/11/07 18:18:18 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_draw_pixel(t_fract *e, int x, int y, int c)
{
	int	bit;
	int	line;
	int	ed;

	e->p_img = mlx_get_data_addr(e->img, &(bit), &(line), &(ed));
	e->p_img[y * bit / 8 + x * line] = (unsigned char)(c & 0xff);
	e->p_img[y * bit / 8 + 1 + x * line] = (unsigned char)(c >> 8) & 0xff;
	e->p_img[y * bit / 8 + 2 + x * line] = (unsigned char)(c >> 16) & 0xff;
}

void		ft_draw_image(t_fract *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(e->mlx, e->win, e->img, WIDTH / 2, HEIGHT / 2);
	if (e->type == 1)
		ft_draw_julia(e);
	else if (e->type == 2)
		ft_draw_mandelbrot(e);
	else if (e->type == 3)
		ft_draw_unknow(e);
	if (e->guide && (!(WIDTH < 500) || !(HEIGHT < 600)))
	{
		mlx_string_put(e->mlx, e->win, 10, 10, DEFAULT, "[UP] INC DPTH");
		mlx_string_put(e->mlx, e->win, 10, 35, DEFAULT, "[DOWN] DEC DEPTH");
		mlx_string_put(e->mlx, e->win, 10, 60, DEFAULT, "[LEFT]  ZOOM OUT");
		mlx_string_put(e->mlx, e->win, 10, 85, DEFAULT, "[RIGHT] ZOOM IN");
		mlx_string_put(e->mlx, e->win, 10, 110, DEFAULT, "[ARROW]  MOVE MAP");
		mlx_string_put(e->mlx, e->win, 10, 135, DEFAULT, "[SPACE]  RESET");
	}
	mlx_destroy_image(e->mlx, e->img);
}

int			set_color(int state)
{
	const int	color[] = {COL1, COL2, COL3, COL4, COL5};
	int			round;

	if ((state % 10) >= (sizeof(color) / sizeof(int)))
		round = state + (10 - (state % 10));
	else
		round = state - (state % 10);
	return (color[abs(state - round)]);
}

void		ft_draw_mandelbrot(t_fract *e)
{
	int		axe[2];
	double	c[2];
	double	d[2];
	int		iter;
	double	x_new;

	axe[1] = 0;
	while (axe[1] < (HEIGHT + e->zoom))
	{
		axe[0] = 0;
		while (axe[0] < (WIDTH + e->zoom))
		{
			c[0] = (axe[0] - (WIDTH + e->zoom) / 2.0) * 4.0 / (WIDTH + e->zoom);
			c[1] = (axe[1] - (HEIGHT + e->zoom) / 2.0) * 4.0 / (WIDTH + e->zoom);
			d[0] = 0;
			d[1] = 0;
			iter = 0;
			while (((d[0] * d[0]) + (d[1] * d[1])) <= 4 && iter < e->size)
			{
				x_new = (d[0] * d[0]) - (d[1] * d[1]) + c[0];
				d[1] = 2 * d[0] * d[1] + c[1];
				d[0] = x_new;
				iter++;
			}
			ft_draw_pixel(e, axe[1] + e->midX, axe[0] + e->midY, set_color(iter));
			axe[0]++;
		}
		axe[1]++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void		ft_draw_julia(t_fract *e)
{
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	movex;
	double	movey;
	int		maxiterations;
	int		y;
	int		x;
	int		i;

	movex = 0;
	movey = 0;
	maxiterations = 300;
	cre = -0.7;
	cim = 0.27015;
	y = 0;
	while (y++ < HEIGHT)
	{
		for (x = 0; x < WIDTH; x++)
		{
			newre = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + movex;
			newim = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + movey;
			for (i = 0; i < maxiterations; i++)
			{
				oldre = newre;
				oldim = newim;
				newre = oldre * oldre - oldim * oldim + cre;
				newim = 2 * oldre * oldim + cim;
				if ((newre * newre + newim * newim) > 4)
					break ;
			}
			ft_draw_pixel(e, x, y, COL1);
		}
	}
}

void		ft_draw_unknow(t_fract *e)
{
	(void)e;
}
