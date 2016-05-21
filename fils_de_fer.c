/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:56:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/05/21 21:50:02 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

static int		get_key(int keycode, t_struct *t_var)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

static int		get_map(t_struct **t_var, int fd)
{
	char	*line;

	if (fd >= 0)
	{
		if (!(*t_var = (t_struct *)ft_memalloc(sizeof(t_struct))))
			return (0);
		MAP = ft_strnew(BUFF_SIZE);
		XMAX = 0;
		YMAX = 0;
		while (get_next_line(fd, &line))
		{
			if (!XMAX)
				XMAX = ft_strlen(line);
			if (XMAX != ft_strlen(line))
				return (0);
			YMAX++;
			MAP = ft_strjoinfree(MAP, line);
			MAP = ft_strjoinfree(MAP, " ");
			free(line);
		}
		PLS = ft_strsplit(MAP, ' ');
		free(MAP);
		return (1);
	}
	return (0);
}

static void		get_coor_in_tab(t_struct **t_var)
{
	int		y;

	y = -1;
	while (PLS[++y])
	{
		TAB[y]->z = ft_atoi(PLS[y]);

	}
}

int		fils_de_fer(int fd, char *map)
{
	t_struct	*t_var;
	int			y;

	if (get_map(&t_var, fd))
	{
		get_coor(&t_var);
		y = 0;
		while (t_var->tab[y])
		{
			ft_putstr(t_var->tab[y]);
			ft_putstr("\n");
			y++;
		}
		MLX = mlx_init();
		WIN = mlx_new_window(MLX, 500, 500, map);
		mlx_key_hook(WIN, get_key, t_var);
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
			if (!(fils_de_fer(fd, av[i])))
				ft_putstr("error");
			close(fd);
		}
	}
	return (0);
}
