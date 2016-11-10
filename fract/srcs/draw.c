/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:13 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 17:51:35 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_env *e, int x, int y, t_color color)
{
	int		bpp;
	int		s_line;
	int		ed;

	e->pixel_img = mlx_get_data_addr(e->img, &bpp, &s_line, &ed);
	e->pixel_img[x * bpp / 8 + y * s_line] = (unsigned char)color.b;
	e->pixel_img[x * bpp / 8 + 1 + y * s_line] = (unsigned char)color.g;
	e->pixel_img[x * bpp / 8 + 2 + y * s_line] = (unsigned char)color.r;
}

int			expose_hook(int x, int y, t_env *e)
{
	e->img = mlx_new_image(e->mlx, W, H);
	if (x > 1 && x < 1300)
		e->pr = (double)x / 1300;
	if (x > 1 && x < 1300)
		e->pi = (double)y / 1300;
	if (e->type == 0)
		julia(e);
	else if (e->type == 1)
		mandel(e);
	else if (e->type == 2)
	{
		exit(0);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}
