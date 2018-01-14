/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:03:57 by itoth             #+#    #+#             */
/*   Updated: 2017/04/05 16:33:39 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define WIDTH 640
# define HEIGHT 480

# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define T 17
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct			s_img
{
	void				*img_ptr;
	unsigned char		*img;
	int					bpp;
	int					sl;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_vec3				color;
	int					ftype;
	int					iter;
	int					x;
	int					y;
	int					theme;
	double				xbot;
	double				xtop;
	double				ybot;
	double				ytop;
	double				xorir;
	double				xoril;
	double				xs;
	double				ys;
}						t_env;

t_vec3					culori(double x, int theme);
void					init_sval(t_env *e);
void					init_env(t_env *e, int ac, char **argv);
double					combine(double x, double y, double a);
void					calculate_m(t_env *e, double x0, double y0);
void					mandelbrot(t_env *e);
void					calculate_j(t_env *e, double x0, double y0);
void					julia(t_env *e);
int						key_press(int keycode, t_env *e);
int						mouse2(int x, int y, t_env *e);
int						mouse(int button, int x, int y, t_env *e);
void					pixel_put(t_env *e);
void					error_arg(int n);
int						frac_type(int ac, char **av);
void					calculate_n(t_env *e, double x0, double yo);
void					newton(t_env *e);
double					scaledy(t_env *e, int y);
double					scaledx(t_env *e, int x);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putchar_fd(char c, int fd);
int						expose_hook(t_env *e);

#endif
