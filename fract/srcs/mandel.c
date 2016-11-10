/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:04:32 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 12:30:44 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mandel(t_env *e)
{
	e->m = (t_mandel*)malloc(sizeof(t_mandel));
}

void		mandel(t_env *e)
{
    t_color		color;
	t_mandel	*m;

	m = e->m;
    e->y = 0;
    while (e->y < HEIGHT)
	{
			e->x = 0;
			while (e->x < WIDTH)
		{
			e->pr = 1.5 * (e->x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->moveX;
			e->pi = (e->y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->moveY;
			m->newRe = m->newIm = m->oldRe = m->oldIm = 0;
			int i = 0;
			while (i < e->iter)
			{
				m->oldRe = m->newRe;
				m->oldIm = m->newIm;
				m->newRe = m->oldRe * m->oldRe - m->oldIm * m->oldIm + e->pr;
				m->newIm = 2 * m->oldRe * m->oldIm + e->pi;
				if ((m->newRe * m->newRe + m->newIm * m->newIm) > 4)
					break;
				i++;
			}
			color = (t_color) {0, 200 *i , 255 * (i < e->iter)};
			draw_pixel(e, e->x, e->y, color);
			e->x++;
		}
		e->y++;
	}
}
