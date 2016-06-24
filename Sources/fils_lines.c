/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:54:22 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/24 22:27:56 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

int		find_x(t_struct *t_var, int x, int y)
{
	return (ZOOM * (CT1 * x - CT2 * y) + (WIDTH_WIN / 2 + WI));
}

int		find_y(t_struct *t_var, int x, int y)
{
	Z = H * ft_atoi(TAB[y][x]);
	if (!COLOR)
	{
		if (Z > 100)
			COLOR = mlx_get_color_value(MLX, 0xFFFFFF);
		if (Z <= 100 && Z > 40)
			COLOR = mlx_get_color_value(MLX, 0x582900);
		if (Z <= 40 && Z > 0)
			COLOR = mlx_get_color_value(MLX, 0x3A9D23);
		if (Z <= 0 && Z > -20)
			COLOR = mlx_get_color_value(MLX, 0x1E7FCB);
		if (Z <= -20)
			COLOR = mlx_get_color_value(MLX, 0x003366);
	}
	return ((ZOOM * (CT1 / A * x + CT2 / A * y) - Z) + (HEIGHT_WIN / 3 + HI));
}

void	fils_line_x(t_struct *t_var)
{
	int		x;
	int		y;

	y = -1;
	while (++y < YMAX)
	{
		x = -1;
		while (++x < XMAX - 1)
		{
			get_color(t_var, y, x);
			X1 = find_x(t_var, x, y);
			X2 = find_x(t_var, x + 1, y);
			Y1 = find_y(t_var, x, y);
			Y2 = find_y(t_var, x + 1, y);
			if ((X1 >= 0 && Y1 >= 0 && X1 < WIDTH_WIN && Y1 < HEIGHT_WIN) &&
					(X2 >= 0 && Y2 >= 0 && X2 < WIDTH_WIN && Y2 < HEIGHT_WIN))
				draw_lines(t_var);
		}
	}
}

void	fils_line_y(t_struct *t_var)
{
	int		x;
	int		y;

	y = -1;
	while (++y < YMAX - 1)
	{
		x = -1;
		while (++x < XMAX)
		{
			get_color(t_var, y, x);
			X1 = find_x(t_var, x, y);
			X2 = find_x(t_var, x, y + 1);
			Y1 = find_y(t_var, x, y);
			Y2 = find_y(t_var, x, y + 1);
			if ((X1 >= 0 && Y1 >= 0 && X1 < WIDTH_WIN && Y1 < HEIGHT_WIN) &&
					(X2 >= 0 && Y2 >= 0 && X2 < WIDTH_WIN && Y2 < HEIGHT_WIN))
				draw_lines(t_var);
		}
	}
}

int		fils_lines(t_struct *t_var)
{
	fils_line_x(t_var);
	fils_line_y(t_var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
