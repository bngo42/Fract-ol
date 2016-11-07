/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:05:38 by bngo              #+#    #+#             */
/*   Updated: 2016/11/07 19:27:15 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	ft_zoom(t_fract *e, int zoom, int x, int y)
{
	(void)x;
	(void)y;

	e->midX += -x * zoom;
	e->midY += -y * zoom;
	e->zoom += zoom;
}

int		mouse_event(int button, int x, int y, t_fract *ptr)
{
	if (button == RMOUSE && ptr->zoom > 1)
		ft_zoom(ptr, -10, x, y);
	else if (button == LMOUSE)
		ft_zoom(ptr, 10, x, y);
	ft_draw_image(ptr);
	printf("MOUSECODE: %i X: %i Y: %i\n", button, x, y);
	return (0);
}

int			key_event(int keycode, t_fract *ptr)
{

	if (keycode == DOWN && ptr->size > 0)
	{
		ptr->size--;
		//ft_draw_image(ptr);
	}
	else if (keycode == UP)
	{
		ptr->size++;
		//ft_draw_image(ptr);
	}
	else if (keycode == ESC)
	{
		free(ptr);
		exit(0);
	}
	else if (keycode == HELP)
	{
		ptr->guide = (ptr->guide == 0) ? 1 : 0;
		//ft_draw_image(ptr);
	}
	else if (keycode == SPACE)
	{
		ptr->size = 10;
		ptr->zoom = 0;
		ptr->midX = 0;
		ptr->midY = 0;
		//ft_draw_image(ptr);
	}
	ft_draw_image(ptr);
	return (0);
}
