/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:34:40 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/20 12:26:20 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "../inc/keycode.h"
#include "../inc/fdf.h"

int	fdf_exit(t_fdf *fdf)
{
	free_map(&fdf->map);
	if (fdf->mlx.mlx && fdf->mlx.window)
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.window);
	if (fdf->mlx.mlx && fdf->mlx.image)
		mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.image);
	exit(fdf->flag.exit_value);
}

void	add_hook(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx.window, key_hook, fdf);
	mlx_hook(fdf->mlx.window, KEYPRESS, 0, move_hook, fdf);
	mlx_hook(fdf->mlx.window, DESTROYNOTIFY, 0, fdf_exit, fdf);
}

int	display_mlx_win(t_fdf *fdf)
{
	fdf->mlx.mlx = mlx_init();
	if (fdf->mlx.mlx != NULL)
	{
		fdf->mlx.window = mlx_new_window(fdf->mlx.mlx, fdf->mlx.win_size.x, \
										fdf->mlx.win_size.y, "fdf");
		if (fdf->mlx.window != NULL)
		{
			fdf->mlx.image = mlx_new_image(fdf->mlx.mlx, \
				fdf->mlx.win_size.x, fdf->mlx.win_size.y);
			if (fdf->mlx.image != NULL)
			{
				fdf->mlx.buff = mlx_get_data_addr(fdf->mlx.image, \
					&fdf->mlx.bpp, &fdf->mlx.buf_wid, &fdf->mlx.endian);
				add_hook(fdf);
				draw_win(fdf);
				mlx_loop(fdf->mlx.mlx);
				return (0);
			}
		}
	}
	return (1);
}
