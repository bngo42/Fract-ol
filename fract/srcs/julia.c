/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:39:10 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 12:17:09 by bngo             ###   ########.fr       */
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
	int		maxIterations;
	int		i;

	maxIterations = 300;
	init_var3(e);
	j = e->j;
	j->y = 0;
	while (j->y < HEIGHT)
	{
		j->x = 0;
		while (j->x < WIDTH)
		{
			j->newre = 1.5 * (j->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
			j->newim = (j->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
			i = 0;
			while (i++ < maxIterations)
			{
				j->oldre = j->newre;
				j->oldim = j->newim;
				j->newre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
				j->newim = 2 * j->oldre * j->oldim + j->cim;
				if((j->newre * j->newre + j->newim * j->newim) > 4) break;
			}
			color = (t_color){i % 255 , 100 * i, 100 * (i < maxIterations)};
			draw_pixel(e, j->x, j->y, color);
			j->x++;
		}
		j->y++;
	}
}

/*
void	julia(t_env *e)
{
	double cRe, cIm;
	double newRe, newIm, oldRe, oldIm;
	double zoom = 1, moveX = 0, moveY = 0;
	t_color color; //the RGB color value for the pixel
	int maxIterations = 300; //after how much iterations the function should stop

	e->j = (t_jul*)malloc(sizeof(t_jul));

	e->j->y = 0;
	cRe = -0.7;
	cIm = 0.27015;
	while (e->j->y < HEIGHT)
	{
		e->j->x = 0;
		while (e->j->x < WIDTH)
		{
			newRe = 1.5 * (e->j->x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
			newIm = (e->j->y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY;
			int i;
			for(i = 0; i < maxIterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				if((newRe * newRe + newIm * newIm) > 4) break;
			}
			color = (t_color){i % 256, 255, 255 * (i < maxIterations)};
			draw_pixel(e, e->j->x, e->j->y, color);
			e->j->x++;
		}
		e->j->y++;
	}
}*/
