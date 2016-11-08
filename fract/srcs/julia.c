/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:39:10 by bngo              #+#    #+#             */
/*   Updated: 2016/11/08 21:18:40 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	julia(t_env *e)
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
