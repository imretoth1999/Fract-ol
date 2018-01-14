/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:54:33 by itoth             #+#    #+#             */
/*   Updated: 2017/03/27 16:57:12 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	combine(double x, double y, double a)
{
	return (x * (1 - a) + y * a);
}

void	calculate_m(t_env *e, double x0, double y0)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	i;

	x = 0.0;
	y = 0.0;
	x2 = e->xs;
	y2 = e->ys;
	i = -1.0;
	while (++i < e->iter && (x2 + y2) < e->iter)
	{
		y = 2.0 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	if (e->theme < 3)
		i = combine(i, i - log2(log2(x2 + y2)), 1.0);
	e->color = culori(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	pixel_put(e);
}

void	mandelbrot(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.height)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.width)
			calculate_m(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}

void	calculate_j(t_env *e, double x0, double y0)
{
	double		x1;
	double		y1;
	double		sco;
	double		i;

	i = -1.0;
	sco = exp(-sqrt(x0 * x0 + y0 * y0));
	while (++i < e->iter && (x0 + y0) < 4.0)
	{
		x1 = x0;
		y1 = y0;
		x0 = x1 * x1 - y1 * y1 + e->xs;
		y0 = 2.0 * x1 * y1 + e->ys;
		sco += exp(-sqrt(x0 * x0 + y0 * y0));
	}
	if (e->theme < 3)
		i = combine(i, sco, 1.0);
	e->color = culori(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	pixel_put(e);
}

void	julia(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.height)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.width)
			calculate_j(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}
