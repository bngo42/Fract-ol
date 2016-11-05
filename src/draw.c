/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:44:34 by bngo              #+#    #+#             */
/*   Updated: 2016/11/05 17:45:03 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

/*
   void		ft_draw_mandelbrot(t_fract *e, int max)
   {
   const int color[] = {COL1, COL2, COL3, COL4, COL5};
   int row;
   int col;
   double c_re;
   double c_im;
   double x;
   double y;
   int iter;
   double x_new;

   row = 0;
   while (row++ < (HEIGHT + e->zoom))
   {
   col = 0;
   while (col++ < (WIDTH + e->zoom))
   {
   c_re = (col - (WIDTH + e->zoom) / 2.0) * 4.0 / (WIDTH + e->zoom);
   c_im = (row - (HEIGHT + e->zoom) / 2.0) * 4.0 / (WIDTH + e->zoom);
   x = 0;
   y = 0;
   iter = 0;
   while (sqrt(x) + sqrt(y) <= 4 && iter < max)
   {
   x_new = sqrt(x) - sqrt(y) + c_re;
   y = 2 * (x * y) + c_im;
   x = x_new;
   iter++;
   }
   ft_draw_pixel(e, row, col, color[iter]);
   }
   }
   mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
   }*/

int			ft_set_color(int state)
{
	const int color[] = {COL1, COL2, COL3, COL4, COL5};
	int round;


	if ((state % 10) >= (sizeof(color) / sizeof(int)))
		round = state + (10 - (state % 10));
	else
		round = state - (state % 10);
	return (color[abs(state - round)]);
}

void		ft_draw_mandelbrot(t_fract *e, int max)
{
	for (int row = 0; row < (HEIGHT + e->zoom); row++) {
		for (int col = 0; col < (WIDTH + e->zoom); col++) {
			double c_re = (col - (WIDTH + e->zoom)/2.0)*4.0/(WIDTH + e->zoom);
			double c_im = (row - (HEIGHT + e->zoom)/2.0)*4.0/(WIDTH + e->zoom);
			double x = 0, y = 0;
			int iter = 0;
			while (x*x+y*y <= 4 && iter < max) {
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iter++;
			}
			ft_draw_pixel(e, row, col, ft_set_color(iter));
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void		ft_draw_julia(t_fract *e)
{
	(void)e;
	double cRe;
	double cIm;//real and imaginary part of the constant c, determinate shape of the Julia Set
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;   //real and imaginary parts of new and old
	double moveX = 0;
	double moveY = 0; //you can change these to zoom and change position
	int maxIterations = 300; //after how much iterations the function should stop
	//pick some values for the constant c, this determines the shape of the Julia Set
	cRe = -0.7;
	cIm = 0.27015;
	//loop through every pixel
	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
		{
			newRe = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + moveX;
			newIm = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + moveY;
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for(i = 0; i < maxIterations; i++)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				//if the point is outside the circle with radius 2: stop
				if((newRe * newRe + newIm * newIm) > 4) break;
			}
			//draw the pixel
			ft_draw_pixel(e, x, y, ft_set_color(i));
		}

}

void		ft_draw_unknow(t_fract *e)
{

	(void)e;
}

