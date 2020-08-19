/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:35:22 by sbump             #+#    #+#             */
/*   Updated: 2020/02/26 21:38:08 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_for_dk(int key, t_fdf *fdf_list)
{
	if (key == 12)
		fdf_list->alpha += 100 * 0.002;
	if (key == 13)
		fdf_list->beta += 100 * 0.002;
	if (key == 14)
		fdf_list->gamma += 100 * 0.002;
	if (key == 0)
		fdf_list->alpha -= 100 * 0.002;
	if (key == 1)
		fdf_list->beta -= 100 * 0.002;
	if (key == 2)
		fdf_list->gamma -= 100 * 0.002;
	if (key == 15)
		fdf_list->alpha = 0;
	if (key == 17)
		fdf_list->beta = 0;
	if (key == 16)
		fdf_list->gamma = 0;
}

int		deal_key(int key, t_fdf *fdf_list)
{
	if (key == 53)
		exit(0);
	if (key == 34)
		fdf_list->iso = 1;
	if (key == 35)
		fdf_list->iso = 0;
	if (key == 126)
		fdf_list->y_shift -= 10;
	if (key == 125)
		fdf_list->y_shift += 10;
	if (key == 124)
		fdf_list->x_shift += 10;
	if (key == 123)
		fdf_list->x_shift -= 10;
	if (key == 6)
		fdf_list->zoom -= 1;
	if (key == 7)
		fdf_list->zoom += 1;
	ft_for_dk(key, fdf_list);
	mlx_clear_window(fdf_list->m, fdf_list->w);
	draw_map(fdf_list);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf_list;

	ft_read_error(argc, argv[1]);
	fdf_list = malloc(sizeof(t_fdf) * 1);
	fdf_read(argv[1], fdf_list);
	fdf_list->m = mlx_init();
	fdf_list->w = mlx_new_window(fdf_list->m, 1000, 1000, "FDF");
	zoom(fdf_list, 1000);
	fdf_list->x_shift = 200;
	fdf_list->y_shift = 200;
	fdf_list->xy = malloc(sizeof(t_xy) * 1);
	fdf_list->alpha = 0;
	fdf_list->beta = 0;
	fdf_list->gamma = 0;
	draw_map(fdf_list);
	mlx_key_hook(fdf_list->w, deal_key, fdf_list);
	mlx_loop(fdf_list->m);
}

void	ft_read_error(int argc, char *argv)
{
	char	buf[1];
	int		i;
	int		fd;

	if (argc != 2)
		ft_exit();
	fd = open(argv, O_RDONLY);
	ft_error(fd, argv);
	if (read(fd, buf, 1) <= 0)
		ft_exit();
	while (read(fd, buf, 1))
	{
		i = 1;
	}
	close(fd);
}

void	ft_error(int fd, char *argv)
{
	int		i;
	char	*s;

	if (fd < 0)
		ft_exit();
	s = ".fdf";
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '.')
		{
			if (ft_strequ(argv + i, s) == 0)
				ft_exit();
			else
				return ;
		}
		i++;
	}
	ft_exit();
}
