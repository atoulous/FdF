/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:22:19 by atoulous          #+#    #+#             */
/*   Updated: 2016/05/20 20:30:50 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILS_DE_FER_H
# define FILS_DE_FER_H

# include "Libft/libft.h"
# include "mlx.h"

# define MAP (*t_var)->map
# define TAB (*t_var)->tab
# define MLX t_var->mlx
# define WIN t_var->win
# define X (*t_var)->x
# define Y (*t_var)->y
# define Z (*t_var)->z
# define XMAX (*t_var)->xmax
# define YMAX (*t_var)->ymax

typedef struct		s_struct
{
	struct s_struct	*next;
	void			*mlx;
	void			*win;
	char			*map;
	char			**tab;
	char			*color;
	int				x;
	int				y;
	int				z;
	int				xmax;
	int				ymax;
}					t_struct;

int					main(int ac, char **av);

#endif
