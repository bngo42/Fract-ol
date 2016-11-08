/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:09 by bngo              #+#    #+#             */
/*   Updated: 2016/11/08 21:58:49 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct    s_color
{
  int             r;
  int             g;
  int             b;
}                 t_color;

typedef struct	s_mandel
{
	double pr;
	double pi;
  double newRe;
  double newIm;
  double oldRe;
  double oldIm;
  double zoom;
  double moveX;
  double	moveY;
  int maxiter;
}			t_mandel;

typedef struct	s_jul
{
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		movex;
	double		movey;
	int			maxiter;
	int			h;
	int			w;
	int			y;
	int			x;
	int			i;
}				t_jul;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			ed;
	int			s_line;
	t_jul		*point;
	t_mandel	*m;
	double		zoom;
	double pr;
	double pi;
	int x;
	int y;
	double moveX;
	double moveY;
}				t_env;

void			draw_pixel(t_env *e, int x, int y, t_color color);
void			mandel(t_env *e);
int				expose_hook(int x, int y, t_env *e);
void			init_var2(t_env *e);
void			julia(t_env *e);

#endif
