/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:00:30 by itoth             #+#    #+#             */
/*   Updated: 2017/03/27 17:00:31 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vec3	culori(double x, int theme)
{
	t_vec3	color;

	color.x = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 0));
	color.y = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 1));
	color.z = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 2));
	return (color);
}

void	init_sval(t_env *e)
{
	if (e->ftype == 1)
	{
		e->xbot = -2.5;
		e->xtop = 1;
		e->ybot = -1;
		e->ytop = 1;
	}
	else if (e->ftype == 2)
	{
		e->xbot = -2;
		e->xtop = 2;
		e->ybot = -2;
		e->ytop = 2;
	}
	else if (e->ftype == 3)
	{
		e->xbot = -4;
		e->xtop = 4;
		e->ybot = -4;
		e->ytop = 4;
		e->xs = e->img.width / 2;
	}
}

void	init_env(t_env *e, int ac, char **av)
{
	t_vec3	help;

	e->ftype = frac_type(ac, av);
	e->img.width = WIDTH;
	e->img.height = HEIGHT;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img.width, e->img.height, "Fract'ol");
	e->img.img_ptr = mlx_new_image(e->mlx, e->img.width, e->img.height);
	e->img.img = (unsigned char *)mlx_get_data_addr(e->img.img_ptr, \
				&e->img.bpp, &e->img.sl, &e->img.endian);
	e->xs = 0;
	e->ys = 0;
	e->iter = 50;
	e->theme = 0;
	help = (t_vec3){0.0, 0.0, 0.0};
	e->color = help;
	init_sval(e);
	e->xoril = e->xbot;
	e->xorir = e->xtop;
}
