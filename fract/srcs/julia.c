/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:39:10 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 16:11:17 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	juliaa(t_env *e)
{
	t_color	color;

	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	movex;
	double	movey;
	double zoom;
	int		maxiterations;
	int		y;
	int		x;
	int		i;

	movex = 0;
	movey = 0;
	zoom = 1;
	maxiterations = 60;
	cre = -0.7;
	cim = 0.27015;
	y = 0;
	while (y++ < HEIGHT)
	{
		for (x = 0; x < WIDTH; x++)
		{
			newre = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + movex;
			newim = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + movey;
			for (i = 0; i < maxiterations; i++)
			{
				oldre = newre;
				oldim = newim;
				newre = oldre * oldre - oldim * oldim + cre;
				newim = 2 * oldre * oldim + cim;
				if ((newre * newre + newim * newim) > 4)
					break ;
			}
			color = (t_color) {i % 128, 0, 128 * (i < maxiterations)};
			draw_pixel(e, x, y, color);
		}
	}
}

void	init_var3(t_env *e)
{
	e->j = (t_jul*)malloc(sizeof(t_jul));
	e->j->cre = -0.7;
	e->j->cim = 0.27015;
}

void	julia(t_env *e)
{
	t_jul	*j;
	t_color	color;
	int		i;

	//init_var3(e);
	j = e->j;
	j->y = 0;
	while (j->y < HEIGHT)
	{
		j->x = 0;
		while (j->x < WIDTH)
		{
			j->nre = 1.5 * (j->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
			j->nim = (j->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
			i = 0;
			while (i < e->iter && ((j->nre * j->nre + j->nim * j->nim) < 4))
			{
				j->oldre = j->nre;
				j->oldim = j->nim;
				j->nre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
				j->nim = 2 * j->oldre * j->oldim + j->cim;
				i++;
			}
			color = (t_color){i % 255 *i , 1 *i, 255 * (i < e->iter)};
			draw_pixel(e, j->x, j->y, color);
			j->x++;
		}
		j->y++;
	}
}
