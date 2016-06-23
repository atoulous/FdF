/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:56:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/23 20:14:49 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

void	reset_pos(t_struct *t_var)
{
	ZOOM = YMAX < 30 ? 20 : 10;
	H = 1;
	WI = 0;
	HI = 0;
	A = 2;
}

int		get_key(int keycode, t_struct *t_var)
{
	if (keycode == 53)
	{
		free_fils(t_var);
		exit(EXIT_SUCCESS);
	}
	refresh_screen(t_var);
	if (keycode == 24 || keycode == 69)
		ZOOM += (ZOOM < 200) ? 2 : 0;
	if (keycode == 27 || keycode == 78)
		ZOOM -= (ZOOM > 0) ? 2 : 0;
	if (keycode == 123 || keycode == 124)
		WI += keycode == 123 ? -20 : 20;
	if (keycode == 125 || keycode == 126)
		HI += keycode == 125 ? 20 : -20;
	if (keycode == 116)
		H += H < 30 ? 1 : 0;
	if (keycode == 121)
		H -= H > -30 ? 1 : 0;
	if (keycode == 75)
		(A += A < 99 ? 0.1 : 0);
	if (keycode == 67)
		(A -= A > 0.7 ? 0.1 : 0);
	keycode == 49 ? reset_pos(t_var) : 0;
	return (0);
}

int		init_fils_de_flute(t_struct *t_var, char *map)
{
	WIDTH_WIN = (XMAX * 100) > 1920 ? 1920 : XMAX * 100;
	HEIGHT_WIN = (YMAX * 100) > 1080 ? 1080 : YMAX * 100;
	H = 1;
	ZOOM = YMAX < 30 ? 20 : 10;
	BPP = 32;
	WIDTH = (WIDTH_WIN / BPP);
	HEIGHT = (HEIGHT_WIN / BPP);
	HI = 0;
	WI = 0;
	CT1 = 1;
	CT2 = 1;
	A = 2;
	ZMAX = 0;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, map);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (0);
}

void	fils_de_fer(int fd, char *map)
{
	t_struct	*t_var;

	if (!(t_var = (t_struct*)ft_memalloc(sizeof(t_struct))))
		return (exit(EXIT_FAILURE));
	parse_fils_de_feu(t_var, fd);
	init_fils_de_flute(t_var, map);
	mlx_loop_hook(MLX, fils_lines, t_var);
	mlx_hook(WIN, KeyPress, KeyPressMask, get_key, t_var);
	mlx_loop(MLX);
	free_fils(t_var);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		ft_putstr("Usage : ./fdf <map>\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
			fils_de_fer(fd, av[1]);
		else
			ft_putendl("Usage : it's not a valid map, find maps in file Maps");
		close(fd);
	}
	return (0);
}
