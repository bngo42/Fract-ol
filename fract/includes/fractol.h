/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:09 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 12:28:39 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 1000

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_mandel
{
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int			maxiter;
}				t_mandel;

typedef struct	s_jul
{
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
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
	int			type;
	t_jul		*j;
	t_mandel	*m;
	double		zoom;
	double		pr;
	double		pi;
	double		moveX;
	double		moveY;
	int			x;
	int			y;
	int			iter;
}				t_env;

enum			e_value
{
	SL = 0x00FF0000,
	DF = 0x00FFFFFF,
	LMOUSE = 1,
	RMOUSE = 2,
	SCRDN = 4,
	SCRUP = 6,
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
	PAGEUP = 116,
	PAGEDN = 121,
	ESC = 53,
	SPACE = 49,
	HELP = 4
};

void			draw_pixel(t_env *e, int x, int y, t_color color);
void			mandel(t_env *e);
int				expose_hook(int x, int y, t_env *e);
void			init_var2(t_env *e);
void			julia(t_env *e);

#endif
