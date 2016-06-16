/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:56:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/16 13:00:34 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

static int	get_key(int keycode, t_struct *t_var)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

static int	find_x(t_struct *t_var, int x, int y)
{
	Z = H * ft_atoi(TAB[y][x]);
	return (ZOOM * (CT1 * x - CT2 * y) + (WIDTH_WIN / 2));
}

static int	find_y(t_struct *t_var, int x, int y)
{
	Z = H * ft_atoi(TAB[y][x]);
	return ((ZOOM * (CT1 / 2 * x + CT2 / 2 * y) - Z) + (HEIGHT_WIN / 3));
}

static void fils_de_img(t_struct *t_var)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= YMAX)
	{
		x = -1;
		while (++x <= XMAX)
		{
			if (x < XMAX -1 && y < YMAX - 1)
			{
				X1 = find_x(t_var, x, y);
				X2 = find_x(t_var, x + 1, y);
				Y1 = find_y(t_var, x, y);
				Y2 = find_y(t_var, x + 1, y);
				get_color(t_var, y, x);
				draw_line(t_var);
			}
		}
	}
	y = -1;
	while (++y <= YMAX)
	{
		x = -1;
		while (++x < XMAX)
		{
			if (x < XMAX -1 && y < YMAX - 1)
			{
				X1 = find_x(t_var, x, y);
				X2 = find_x(t_var, x, y + 1);
				Y1 = find_y(t_var, x, y);
				Y2 = find_y(t_var, x, y + 1);
				get_color(t_var, y, x);
				draw_line(t_var);
			}
		}
	}

}

static void	fils_de_fer(int fd, char *map)
{
	t_struct	*t_var;

	if (!(t_var = (t_struct*)ft_memalloc(sizeof(t_struct))))
		return (exit(EXIT_FAILURE));
	ZMAX = 0;
	get_map(t_var, fd);
	WIDTH_WIN = (XMAX * 50) > 1920 ? 1920 : XMAX * 50;
	HEIGHT_WIN = (YMAX * 50) > 1080 ? 1080 : YMAX * 50;
	H = 10;
	ZOOM = 20;
	BPP = 32;
	WIDTH = (WIDTH_WIN / BPP);
	HEIGHT = (HEIGHT_WIN / BPP);
	CT1 = 1;
	CT2 = 1;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, map);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	fils_de_img(t_var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_key_hook(WIN, get_key, t_var);
	mlx_loop(MLX);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	if (ac < 2)
		ft_putstr("Usage : ./fdf <filename>\n");
	else
	{
		i = 0;
		while (ac > ++i)
		{
			fd = open(av[i], O_RDONLY);
			if (fd > 0)
				fils_de_fer(fd, av[i]);
			close(fd);
		}
	}
	return (0);
}
