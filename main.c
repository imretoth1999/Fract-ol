/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:03:42 by itoth             #+#    #+#             */
/*   Updated: 2017/03/27 19:18:04 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *e)
{
	int		pos;

	pos = (e->x * e->img.bpp / 8) + (e->y * e->img.sl);
	e->img.img[pos] = (int)(e->color.z * 256) % 256;
	e->img.img[pos + 1] = ((int)(e->color.y * 256) % 256);
	e->img.img[pos + 2] = ((int)(e->color.x * 256) % 256);
}

void	error_arg(int n)
{
	if (n == 0)
		ft_putstr_fd("No paramater found\n", 2);
	else
		ft_putstr_fd("Incorrect paramater\n", 2);
	ft_putstr_fd("USAGE: ./fractol M or ./fractol J or ./fractol N\n", 2);
	exit(EXIT_FAILURE);
}

int		frac_type(int ac, char **av)
{
	if (ac < 2)
		error_arg(0);
	if (av[1][0] == 'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'N')
		return (3);
	error_arg(1);
	return (0);
}

int		main(int ac, char **av)
{
	t_env e;

	init_env(&e, ac, av);
	mlx_key_hook(e.win, key_press, &e);
	mlx_mouse_hook(e.win, mouse, &e);
	mlx_hook(e.win, 6, 64, &mouse2, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
