/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:56:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/17 21:52:45 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

void	reset_pos(t_struct *t_var)
{
	ZOOM = 20;
	H = 1;
	WI = 0;
	HI = 0;
	CT1 = 1;
	CT2 = 1;
}

int		get_key(int keycode, t_struct *t_var)
{
	refresh_screen(t_var);
	if (keycode == 53)
		exit(0);
	if (keycode == 24 || keycode == 69)
		ZOOM += (ZOOM < 50) ? 2 : 0;
	if (keycode == 27 || keycode == 78)
		ZOOM -= (ZOOM > 0) ? 2 : 0;
	if (keycode == 123 || keycode == 124)
		WI += keycode == 123 ? -10 : 10;
	if (keycode == 125 || keycode == 126)
		HI += keycode == 125 ? 10 : -10;
	if (keycode == 116 || keycode == 121)
		H += keycode == 116 ? 1 : -1;
	if (keycode == 8)
		(CT1 += CT1 < 1 ? 0.1 : 0) && (CT2 += CT2 < 1 ? 0.1 : 0);
	if (keycode == 9)
		(CT1 -= CT1 > 0.5 ? 0.1 : 0) && (CT2 -= CT2 > 0.5 ? 0.1 : 0);
	if (keycode == 49)
		reset_pos(t_var);
	return (1);
}

int		init_fils_de_flute(t_struct *t_var, char *map)
{
	WIDTH_WIN = (XMAX * 100) > 1920 ? 1920 : XMAX * 100;
	HEIGHT_WIN = (YMAX * 100) > 1080 ? 1080 : YMAX * 100;
	H = 1;
	ZOOM = 20;
	BPP = 32;
	WIDTH = (WIDTH_WIN / BPP);
	HEIGHT = (HEIGHT_WIN / BPP);
	HI = 0;
	WI = 0;
	CT1 = 1;
	CT2 = 1;
	ZMAX = 0;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, map);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (1);
}

void	fils_de_fer(int fd, char *map)
{
	t_struct	*t_var;

	if (!(t_var = (t_struct*)ft_memalloc(sizeof(t_struct))))
		return (exit(EXIT_FAILURE));
	parse_fils_de_feu(t_var, fd);
	init_fils_de_flute(t_var, map);
	mlx_loop_hook(MLX, fils_lines, t_var);
	//mlx_expose_hook(WIN, fils_lines, t_var);
	//mlx_key_hook(WIN, get_key, t_var);
	mlx_hook(WIN, 2, 3, get_key, t_var);
	mlx_loop(MLX);
	mlx_destroy_image(MLX, IMG);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		ft_putstr("Usage : ./fdf <filename>\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
			fils_de_fer(fd, av[1]);
		close(fd);
	}
	return (0);
}
