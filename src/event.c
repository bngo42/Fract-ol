/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:05:38 by bngo              #+#    #+#             */
/*   Updated: 2016/11/05 12:26:20 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_event(int keycode, t_fract *ptr)
{
	if (keycode == LEFT)
	{
		ptr->zoom -= 10;
		ft_draw_mandelbrot(ptr, ptr->size);
	}
	else if (keycode == RIGHT)
	{
		ptr->zoom += 10;
		ft_draw_mandelbrot(ptr, ptr->size);
	}
	else if (keycode == DOWN && ptr->size > 0)
	{
		ptr->size--;
		ft_draw_mandelbrot(ptr, ptr->size);
	}
	else if (keycode == UP)
	{
		ptr->size++;
		ft_draw_mandelbrot(ptr, ptr->size);
	}
	else if (keycode == ESC)
	{
		free(ptr);
		exit(0);
	}
	return (0);
}
