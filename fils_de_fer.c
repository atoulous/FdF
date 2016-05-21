/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:56:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/05/20 20:30:47 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

static int		get_map_in_tab(t_struct **t_var, int fd)
{
	char	*line;

	if (fd >= 0)
	{
		if (!(*t_var = (t_struct *)malloc(sizeof(t_struct))))
			return (0);
		MAP = ft_strnew(BUFF_SIZE);
		while (get_next_line(fd, &line))
		{
			if (!XMAX)
				XMAX = ft_strlen(line);
			YMAX++;
			MAP = ft_strjoinfree(MAP, line);
			MAP = ft_strjoinfree(MAP, " ");
			free(line);
		}
		TAB = ft_strsplit(MAP, ' ');
		free(MAP);
		return (1);
	}
	return (0);
}

static int		get_coor_in_tab(t_struct **t_var)
{
	int		y;
	int		x;

	y = -1;
	while (TAB[++y])
	{
		x = -1;
		while (TAB[y][++x])
		{
			ft_atoi(TAB[y][x]);



int		fils_de_fer(int fd, char *map)
{
	t_struct	*t_var;
	int			y;

	if (get_map_in_tab(&t_var, fd))
	{
		y = 0;
		while (t_var->tab[y])
		{
			ft_putstr(t_var->tab[y]);
			ft_putstr("\n");
			y++;
		}
		MLX = mlx_init();
		WIN = mlx_new_window(MLX, 500, 500, map);
		mlx_loop(MLX);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	if (ac < 2)
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	else
	{
		i = 0;
		while (ac > ++i)
		{
			fd = open(av[i], O_RDONLY);
			fils_de_fer(fd, av[i]);
			close(fd);
		}
	}
	return (0);
}
