/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <bngo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:58:09 by bngo              #+#    #+#             */
/*   Updated: 2016/11/10 17:47:23 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 1200
# define H 1000

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
	double		nre;
	double		nim;
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
	double		mvx;
	double		mvy;
	int			mousex;
	int			mousey;
	int			x;
	int			y;
	int			iter;
	int			freeze;
}				t_env;

enum			e_value
{
	DEFAULT = 0x00FFFFFF,
	COL1 = 0x00148FCC,
	COL2 = 0x003D7B99,
	COL3 = 0x0000FFC9,
	COL4 = 0x00FF5640,
	COL5 = 0x00CC1428,
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

void			init_var3(t_env *e);

void			draw_pixel(t_env *e, int x, int y, t_color color);
void			mandel(t_env *e);
int				expose_hook(int x, int y, t_env *e);
void			init_var2(t_env *e);
void			julia(t_env *e);

#endif
