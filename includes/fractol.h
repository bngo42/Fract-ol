/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:45:30 by bngo              #+#    #+#             */
/*   Updated: 2016/11/04 18:11:04 by bngo             ###   ########.fr       */
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
}					t_fract;

enum				e_value
{
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
void				ft_draw_mandelbrot(t_fract *e);
void				ft_draw_unknow(t_fract *e);

#endif
