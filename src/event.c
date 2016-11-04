/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:05:38 by bngo              #+#    #+#             */
/*   Updated: 2016/11/04 14:17:07 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_event(int keycode, t_fract *ptr)
{
	if (keycode == LEFT)
		ft_putendl("CACA");
	else if (keycode == RIGHT)
		ft_putendl("CACA");
	else if (keycode == DOWN)
		ft_putendl("CACA");
	else if (keycode == UP)
		ft_putendl("CACA");
	else if (keycode == ESC)
	{
		free(ptr);
		exit(0);
	}
	return (0);
}
