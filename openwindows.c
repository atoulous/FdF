/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openwindows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 19:32:34 by atoulous          #+#    #+#             */
/*   Updated: 2016/05/20 16:12:55 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx.h"
#include <stdio.h>

int		mykey(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return(printf("%d\n", keycode));
}

int		main()
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;

	x = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "new_window");
	img = mlx_new_image(mlx, 300, 300);
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	mlx_put_image_to_window(mlx, win, img, 300, 300);
	printf("data==%s\n", data);
	//while (x++ < 250)
	//	mlx_pixel_put(mlx, win, x, x, 0x00FFFFFF);
	mlx_key_hook(win, mykey, 0);
	mlx_loop(mlx);
	return (0);
}
