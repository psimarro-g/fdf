/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:50:00 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/20 12:27:23 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include <mlx.h>
#include "../inc/fdf.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*img;

	img = mlx->buff;
	if (x >= 0 && x < mlx->win_size.x && y >= 0 && y < mlx->win_size.y)
	{
		img = mlx->buff + (y * mlx->buf_wid + x * (mlx->bpp / 8));
		*(unsigned int *)img = color;
	}
}

void	draw_helper(t_fdf *fdf, int c)
{
	void	*win;
	int		x;
	int		y;
	char	*s;

	y = 20;
	s = ft_itoa(fdf->flag.z_angle);
	win = fdf->mlx.window;
	x = fdf->mlx.win_size.x - 270;
	mlx_string_put(fdf->mlx.mlx, win, x - 20, y, c, "Usage");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 30, c, "Show usage    space");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 55, c, "Move          < ^ v >");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 80, c, "Move          a w s d");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 105, c, "Zoom          + -");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 130, c, "Scale up      page up");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 155, c, "Scale down    page down");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 180, c, "Projection    p");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 205, c, "Z angle       z c");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 230, c, s);
	free(s);
	s = ft_itoa(fdf->flag.angle);
	mlx_string_put(fdf->mlx.mlx, win, x, y + 255, c, "Angle         q e");
	mlx_string_put(fdf->mlx.mlx, win, x, y + 280, c, s);
	free(s);
}

void	clear_image(t_mlx *mlx, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->win_size.x)
	{
		y = 0;
		while (y < mlx->win_size.y)
		{
			put_pixel(mlx, x, y, color);
			++y;
		}
		++x;
	}
}

void	draw_usage_bg(t_fdf *fdf, int color)
{
	int	i;
	int	j;

	i = fdf->mlx.win_size.x - 300;
	while (i < fdf->mlx.win_size.x - 10)
	{
		j = 15;
		while (j < 325)
		{
			put_pixel(&fdf->mlx, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_win(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.window);
	clear_image(&fdf->mlx, fdf->disp.bg_color);
	draw_fdf(fdf);
	if (!fdf->flag.disp_helper)
		draw_usage_bg(fdf, fdf->disp.usage_color);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.window, fdf->mlx.image,
		0, 0);
	if (!fdf->flag.disp_helper)
		draw_helper(fdf, fdf->disp.text_color);
}
