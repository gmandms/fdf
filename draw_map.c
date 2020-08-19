/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:23:15 by sbump             #+#    #+#             */
/*   Updated: 2020/02/26 21:23:18 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_fdf *fdf_list)
{
	int x;
	int y;

	y = 0;
	while (y < fdf_list->max_y)
	{
		x = 0;
		while (x < fdf_list->max_x)
		{
			if (x < fdf_list->max_x - 1)
			{
				ft_t_xx(x, y, fdf_list);
				bresenham(fdf_list);
			}
			if (y < fdf_list->max_y - 1)
			{
				ft_t_yy(x, y, fdf_list);
				bresenham(fdf_list);
			}
			x++;
		}
		y++;
	}
}

void	ft_t_xx(int x, int y, t_fdf *fdf_list)
{
	fdf_list->xy->x = x;
	fdf_list->xy->y = y;
	fdf_list->xy->x1 = x + 1;
	fdf_list->xy->y1 = y;
}

void	ft_t_yy(int x, int y, t_fdf *fdf_list)
{
	fdf_list->xy->x = x;
	fdf_list->xy->y = y;
	fdf_list->xy->x1 = x;
	fdf_list->xy->y1 = y + 1;
}

void	ft_write_z_matrix(t_fdf *fdf_list)
{
	int x;
	int y;
	int j;

	j = 0;
	fdf_list->z_matrix = malloc(sizeof(int*) * fdf_list->max_y);
	y = 0;
	while (y < fdf_list->max_y)
	{
		fdf_list->z_matrix[y] = malloc(sizeof(int) * fdf_list->max_x);
		x = 0;
		while (x < fdf_list->max_x)
		{
			fdf_list->z_matrix[y][x] = fdf_list->z[j];
			x++;
			j++;
		}
		y++;
	}
}

void	ft_exit(void)
{
	write(1, "FDF it's not a joke!\n", 21);
	exit(0);
}
