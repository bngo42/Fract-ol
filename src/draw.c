/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:44:34 by bngo              #+#    #+#             */
/*   Updated: 2016/11/04 18:12:13 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_draw_image(t_fract *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(e->mlx, e->win, e->img, WIDTH / 2, HEIGHT / 2);
	if (!(WIDTH < 500) || !(HEIGHT < 600))
	{
		mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, "[PAGEUP] ZOOM IN");
		mlx_string_put(e->mlx, e->win, 10, 35, 0x00FFFFFF, "[PAGEDN] ZOOM OUT");
		mlx_string_put(e->mlx, e->win, 10, 60, 0x00FFFFFF, "[HOME]   INCREASE LVL");
		mlx_string_put(e->mlx, e->win, 10, 85, 0x00FFFFFF, "[END]    DECREASE LVL");
		mlx_string_put(e->mlx, e->win, 10, 110, 0x00FFFFFF, "[ARROW]  MOVE MAP");
		mlx_string_put(e->mlx, e->win, 10, 135, 0x00FFFFFF, "[SPACE]  RESET");
	}
	mlx_destroy_image(e->mlx, e->img);
}

void		ft_draw_julia(t_fract *e)
{
	(void)e;
}

void		ft_draw_mandelbrot(t_fract *e)
{
	(void)e;
}

void		ft_draw_unknow(t_fract *e)
{

	(void)e;
}

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
