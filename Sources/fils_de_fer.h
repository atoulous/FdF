/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:22:19 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/23 20:14:55 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILS_DE_FER_H
# define FILS_DE_FER_H

# include "../Libs/libft/libft.h"
# include "mlx.h"
# include <math.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define BASE10 "0123456789"
# define BASE16 "0123456789ABCDEF"

# define MAP t_var->map
# define TAB t_var->tab
# define COLOR t_var->color
# define PLS t_var->pls
# define MLX t_var->mlx
# define IMG t_var->img
# define WIN t_var->win
# define DATA t_var->data
# define BPP t_var->bpp
# define SIZELINE t_var->sizeline
# define ENDIAN t_var->endian
# define HEIGHT t_var->height
# define HEIGHT_WIN t_var->height_win
# define WIDTH t_var->width
# define WIDTH_WIN t_var->width_win
# define ZOOM t_var->zoom
# define HI t_var->hi
# define WI t_var->wi
# define X t_var->x
# define X1 t_var->x1
# define X2 t_var->x2
# define Y t_var->y
# define Y1 t_var->y1
# define Y2 t_var->y2
# define DX t_var->dx
# define DY t_var->dy
# define Z t_var->z
# define H t_var->h
# define XMAX t_var->xmax
# define YMAX t_var->ymax
# define ZMAX t_var->zmax
# define CT1 t_var->ct1
# define CT2 t_var->ct2
# define A t_var->a
# define KEY_USE t_var->key_use

typedef struct		s_struct
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*map;
	char			**pls;
	char			***tab;
	unsigned int	color;
	int				bpp;
	int				sizeline;
	int				endian;
	int				height;
	int				height_win;
	int				width;
	int				width_win;
	int				zoom;
	int				hi;
	int				wi;
	int				x;
	int				y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				z;
	int				h;
	int				xmax;
	int				ymax;
	int				zmax;
	float			ct1;
	float			ct2;
	float			a;
	int				key_use;
}					t_struct;

int					main(int ac, char **av);
int					get_key(int keycode, t_struct *t_var);
int					init_fils_de_flute(t_struct *t_var, char *map);
int					fils_lines(t_struct *t_var);
void				fils_de_fer(int fd, char *map);
void				parse_fils_de_feu(t_struct *t_var, int fd);
void				get_color(t_struct *t_var, int y, int x);
void				draw_lines(t_struct *t_var);
void				refresh_screen(t_struct *t_var);
void				fill_image(t_struct *t_var);
void				free_fils(t_struct *t_var);

#endif
