/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 18:45:39 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/16 15:43:34 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

void	fill_img(t_struct *t_var)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int color1;
	unsigned int color2;

	if (COLOR)
	{
		r = COLOR;
		g = COLOR;
		b = COLOR;
	}
	else
	{
		r = mlx_get_color_value(MLX, 0xFF0000 >> 16);
		g = mlx_get_color_value(MLX, 0x00FF00 >> 8);
		b = mlx_get_color_value(MLX, 0x0000FF);
	}
	//printf("%d\n", r);
	DATA[Y * SIZELINE + X * (BPP / 8)] = r;
	DATA[Y * SIZELINE + X * (BPP / 8) + 1] = g;
	DATA[Y * SIZELINE + X * (BPP / 8) + 2] = b;
}

void	draw_line_if(t_struct *t_var, int xinc, int yinc)
{
	int		cumul;
	int		i;

	cumul = DX / 2;
	i = 0;
	while (++i <= DX)
	{
		X += xinc;
		cumul += DY;
		if (cumul >= DX)
		{
			cumul -= DX;
			Y += yinc;
		}
		fill_img(t_var);
	}
}

void	draw_line_else(t_struct *t_var, int xinc, int yinc)
{
	int		cumul;
	int		i;

	cumul = DY / 2;
	i = 0;
	while (++i <= DY)
	{
		Y += yinc;
		cumul += DX;
		if (cumul >= DY)
		{
			cumul -= DY;
			X += xinc;
		}
		fill_img(t_var);
	}
}

void	draw_line(t_struct *t_var)
{
	int		xinc;
	int		yinc;

	X = X1;
	Y = Y1;
	DX = X2 - X1;
	DY = Y2 - Y1;
	xinc = (DX > 0) ? 1 : -1;
	yinc = (DY > 0) ? 1 : -1;
	DX = abs(DX);
	DY = abs(DY);
	fill_img(t_var);
	if (DX > DY)
		draw_line_if(t_var, xinc, yinc);
	else
		draw_line_else(t_var, xinc, yinc);
}
