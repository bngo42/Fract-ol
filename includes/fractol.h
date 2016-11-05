/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:45:30 by bngo              #+#    #+#             */
/*   Updated: 2016/11/05 15:58:55 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000
# define HEIGHT 1000
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
typedef struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*p_img;
	int				size;
	int				zoom;
}					t_fract;

enum				e_value
{
	COL1 = 0x00148FCC,
	COL2 = 0x003D7B99,
	COL3 = 0x0000FFC9,
	COL4 = 0x00FF5640,
	COL5 = 0x00CC1428,
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
	PAGEUP = 116,
	PAGEDN = 121,
	HOME = 115,
	END = 119,
	ESC = 53,
	SPACE = 49
};

int					key_event(int keycode, t_fract *ptr);

void				ft_error(int err);
void				ft_set_fract(int type);

void				ft_draw_julia(t_fract *e);
void				ft_draw_mandelbrot(t_fract *e, int max);
void				ft_draw_unknow(t_fract *e);

#endif
