/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:04:32 by bngo              #+#    #+#             */
/*   Updated: 2016/11/08 21:54:29 by bngo             ###   ########.fr       */
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

	// double pr, pi;           //real and imaginary part of the pixel p
    double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
 //you can change these to zoom and change position
    t_color color; //the RGB color value for the pixel
    int maxIterations = 60;//after how much iterations the function should stop

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
		  color = (t_color) {i % 199, 21, 133 * (i < maxIterations)};
		  draw_pixel(e, e->x, e->y, color);
		   e->x++;
	    }
		e->y++;
	}
}
