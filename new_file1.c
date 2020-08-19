/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:52:12 by sbump             #+#    #+#             */
/*   Updated: 2020/02/28 20:52:15 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, float *z, double alpha)
{
	float pre_y;

	pre_y = *y;
	*y = pre_y * cos(alpha) + *z * sin(alpha);
	*z = -pre_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, float *z, double beta)
{
	float pre_x;

	pre_x = *x;
	*x = pre_x * cos(beta) + *z * sin(beta);
	*z = -pre_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double gamma)
{
	float	pre_x;
	float	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(gamma) - pre_y * sin(gamma);
	*y = pre_x * sin(gamma) + pre_y * cos(gamma);
}

void	rotate_matrix(t_fdf *f, float *z1)
{
	rotate_x(&f->xy->y, &f->zz, f->alpha);
	rotate_x(&f->xy->y1, z1, f->alpha);
	rotate_y(&f->xy->x, &f->zz, f->beta);
	rotate_y(&f->xy->x1, z1, f->beta);
	rotate_z(&f->xy->x, &f->xy->y, f->gamma);
	rotate_z(&f->xy->x1, &f->xy->y1, f->gamma);
}
