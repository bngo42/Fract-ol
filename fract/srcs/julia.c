/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:39:10 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 21:14:59 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	j = e->j;
	j->y = 0;
	while (j->y < H)
	{
		j->x = 0;
		while (j->x < W)
		{
			j->nre = 1.5 * (j->x - W / 2) / (0.5 * e->zoom * W) + e->mvx;
			j->nim = (j->y - H / 2) / (0.5 * e->zoom * H) + e->mvy;
			i = 0;
			while (i++ < e->iter && ((j->nre * j->nre + j->nim * j->nim) < 4))
			{
				j->oldre = j->nre;
				j->oldim = j->nim;
				j->nre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
				j->nim = 2 * j->oldre * j->oldim + j->cim;
			}
			color = (t_color){i % 255 * i, 1 * i, 255 * (i < e->iter)};
			draw_pixel(e, j->x, j->y, color);
			j->x++;
		}
		j->y++;
	}
}
