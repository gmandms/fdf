/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:53:03 by sbump             #+#    #+#             */
/*   Updated: 2020/02/28 20:53:05 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *f, float z1)
{
	if (f->iso == 1)
	{
		isometric(&f->xy->x, &f->xy->y, f->zz);
		isometric(&f->xy->x1, &f->xy->y1, z1);
	}
}

void	ft_zoom(t_fdf *f)
{
	f->xy->x *= (float)f->zoom;
	f->xy->y *= (float)f->zoom;
	f->xy->x1 *= (float)f->zoom;
	f->xy->y1 *= (float)f->zoom;
}

void	ft_shift(t_fdf *f)
{
	f->xy->x += f->x_shift;
	f->xy->y += f->y_shift;
	f->xy->x1 += f->x_shift;
	f->xy->y1 += f->y_shift;
}

void	zoom(t_fdf *fdf_list, int size)
{
	fdf_list->zoom = size / (fdf_list->max_x + fdf_list->max_y);
}
