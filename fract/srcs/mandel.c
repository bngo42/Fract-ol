/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:04:32 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 17:52:05 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel(t_env *e)
{
	t_color		color;
	t_mandel	*m;
	int			i;

	m = e->m;
	e->y = -1;
	while (++e->y < H)
	{
		e->x = -1;
		while (++e->x < W)
		{
			e->pr = 1.5 * (e->x - W / 2) / (0.5 * e->zoom * W) + e->mvx;
			e->pi = (e->y - H / 2) / (0.5 * e->zoom * H) + e->mvy;
			m->newRe = 0;
			m->newIm = 0;
			m->oldRe = 0;
			m->oldIm = 0;
			i = 0;
			while (i++ < e->iter)
			{
				m->oldRe = m->newRe;
				m->oldIm = m->newIm;
				m->newRe = m->oldRe * m->oldRe - m->oldIm * m->oldIm + e->pr;
				m->newIm = 2 * m->oldRe * m->oldIm + e->pi;
				if ((m->newRe * m->newRe + m->newIm * m->newIm) > 4)
					break ;
			}
			color = (t_color) {0, 200 * i, 255 * (i < e->iter)};
			draw_pixel(e, e->x, e->y, color);
		}
	}
}
