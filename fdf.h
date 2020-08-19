/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:53:37 by sbump             #+#    #+#             */
/*   Updated: 2020/02/28 20:55:37 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_xy
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}				t_xy;

typedef struct	s_fdf
{
	int		max_x;
	int		max_y;
	int		zoom;
	int		color;
	int		*z;
	int		**z_matrix;
	void	*m;
	void	*w;
	int		iso;
	int		x_shift;
	int		y_shift;
	float	zz;
	t_xy	*xy;
	double	alpha;
	double	beta;
	double	gamma;
}				t_fdf;

void			fdf_read(char *argv, t_fdf *fdf_list);
int				for_x(char *line);
void			ft_write_yx(char *argv, t_fdf *fdf_list);
void			ft_write_z(char *argv, t_fdf *fdf_list);
int				for_write_z(const char *n, int *i);
void			draw_map(t_fdf *fdf_list);
void			ft_write_z_matrix(t_fdf *fdf_list);
float			ft_mod(float a);
float			ft_max(float a, float b);
void			isometric(float *x, float *y, float z);
void			zoom(t_fdf *fdf_list, int size);
void			bresenham(t_fdf *fdf_list);
void			ft_t_xx(int x, int y, t_fdf *fdf_list);
void			ft_t_yy(int x, int y, t_fdf *fdf_list);
void			ft_zoom(t_fdf *f);
void			ft_shift(t_fdf *f);
void			iso(t_fdf *f, float z1);
void			rotate_x(float *y, float *z, double alpha);
void			rotate_y(float *x, float *z, double beta);
void			rotate_z(float *x, float *y, double gamma);
void			rotate_matrix(t_fdf *f, float *z1);
void			ft_error(int fd, char *argv);
void			ft_read_error(int argc, char *argv);
void			ft_exit();

#endif
