/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:38:32 by sbump             #+#    #+#             */
/*   Updated: 2020/02/26 21:40:40 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	return (a > b ? a : b);
}

float	ft_mod(float a)
{
	return (a < 0 ? -a : a);
}

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(t_fdf *f)
{
	float	x_step;
	float	y_step;
	float	max;
	float	z1;

	f->zz = f->z_matrix[(int)f->xy->y][(int)f->xy->x];
	z1 = f->z_matrix[(int)f->xy->y1][(int)f->xy->x1];
	f->color = (f->zz || z1) ? 0xe80c0c : 0xffffff;
	ft_zoom(f);
	rotate_matrix(f, &z1);
	iso(f, z1);
	ft_shift(f);
	x_step = f->xy->x1 - f->xy->x;
	y_step = f->xy->y1 - f->xy->y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(f->xy->x - f->xy->x1) || (int)(f->xy->y - f->xy->y1))
	{
		mlx_pixel_put(f->m, f->w, (int)f->xy->x, (int)f->xy->y, f->color);
		f->xy->x += x_step;
		f->xy->y += y_step;
	}
}
