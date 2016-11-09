/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:04:32 by bngo              #+#    #+#             */
/*   Updated: 2016/11/09 17:54:49 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_var2(t_env *e)
{
	e->m->zoom = 1;
	e->m->moveX = -0.5;
	e->m->moveY = 0;
	e->m->maxiter = 50;
}

void		mandel(t_env *e)
{
    double	newRe, newIm, oldRe, oldIm;
    t_color	color;
	int		maxIterations = 60;

    e->y = 0;
    while (e->y < HEIGHT)
	{
			e->x = 0;
			while (e->x < WIDTH)
		{
			e->pr = 1.5 * (e->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
			e->pi = (e->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
			newRe = newIm = oldRe = oldIm = 0;
			int i = 0;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + e->pr;
				newIm = 2 * oldRe * oldIm + e->pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
				i++;
			}
			color = (t_color) {i % 199 *i , 21 *i , 133 * (i < maxIterations)};
			draw_pixel(e, e->x, e->y, color);
			e->x++;
		}
		e->y++;
	}
}
