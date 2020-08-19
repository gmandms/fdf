/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:23:52 by sbump             #+#    #+#             */
/*   Updated: 2020/02/26 21:30:16 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_read(char *argv, t_fdf *fdf_list)
{
	ft_write_yx(argv, fdf_list);
	fdf_list->z = malloc(sizeof(int) * (fdf_list->max_y * fdf_list->max_x));
	ft_write_z(argv, fdf_list);
	ft_write_z_matrix(fdf_list);
}

void	ft_write_z(char *argv, t_fdf *fdf_list)
{
	char	*l;
	int		fd;
	int		i;
	int		j;

	fd = open(argv, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &l) == 1)
	{
		i = 0;
		while (l[i])
		{
			if (ft_isalnum(l[i]) == 1)
			{
				fdf_list->z[j] = for_write_z(l, &i);
				j++;
			}
			i++;
		}
		free(l);
	}
	free(l);
	close(fd);
}

int		for_write_z(const char *l, int *i)
{
	char	*n;
	int		a;
	int		f;

	a = *i;
	f = 1;
	while (ft_isalnum(l[a]))
	{
		a++;
	}
	n = malloc(sizeof(char) * a + 1);
	a = 0;
	while (ft_isalnum(l[*i]))
	{
		if (l[*i - 1] == '-')
			f = -1;
		n[a] = l[*i];
		a++;
		*i += 1;
	}
	n[a] = '\0';
	a = ft_atoi(n);
	a *= f;
	*i -= 1;
	free(n);
	return (a);
}

void	ft_write_yx(char *argv, t_fdf *fdf_list)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	fdf_list->max_y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (fdf_list->max_y == 0)
			fdf_list->max_x = for_x(line);
		else if (fdf_list->max_x != for_x(line))
			exit(0);
		fdf_list->max_y++;
		free(line);
	}
	free(line);
	close(fd);
}

int		for_x(char *l)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (l[i] != '\0')
	{
		if (l[i] != ' ' && (ft_isalnum(l[i]) != 1) && l[i] != '-')
			ft_exit();
		if ((l[i] == ' ' && 1 == ft_isalnum(l[i - 1])) || \
		(ft_isalnum(l[i]) == 1 && l[i + 1] == '\0'))
		{
			x++;
			i++;
		}
		else
			i++;
	}
	return (x);
}
