/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:34:04 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/17 21:49:42 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_fer.h"

void	refresh_screen(t_struct *t_var)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
}

void	get_color(t_struct *t_var, int y, int x)
{
	int		i;
	char	*coolor;

	if (Z > ZMAX)
		ZMAX = Z;
	i = 0;
	while (TAB[y][x][i] != ',' && TAB[y][x][i])
		i++;
	if (TAB[y][x][i] == ',')
	{
		coolor = ft_strsub(TAB[y][x], i + 3, ft_strlen(TAB[y][x]) - i);
		COLOR = ft_atoi(ft_convert_base(coolor, BASE16, BASE10));
		free(coolor);
	}
	else
		COLOR = 0;
}

int		get_xmax(char *line)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i])
		{
			c++;
			while (line[i] != ' ' && line[i])
				i++;
		}
	}
	return (c);
}

void	parse_fils_de_feu(t_struct *t_var, int fd)
{
	char	*line;
	int		y;

	YMAX = 0;
	MAP = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		if (!XMAX)
			XMAX = get_xmax(line);
		MAP = ft_strjoinfree(MAP, line);
		MAP = ft_strjoinfree(MAP, "\n");
		free(line);
		YMAX++;
	}
	PLS = ft_strsplit(MAP, '\n');
	if (!(TAB = (char***)ft_memalloc(sizeof(char**) * YMAX + 1)))
		return (exit(EXIT_FAILURE));
	y = -1;
	while (PLS[++y])
	{
		TAB[y] = ft_strsplit(PLS[y], ' ');
		free(PLS[y]);
	}
	free(PLS);
	free(MAP);
}
