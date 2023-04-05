/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:50:00 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/03 20:43:03 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../mlx/mlx.h"
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

void	draw_helper(t_fdf *fdf, int col)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	y = 20;
	mlx = fdf->mlx.mlx;
	win = fdf->mlx.window;
	x = fdf->mlx.win_size.x - 270;
	mlx_string_put(mlx, win, x - 20, y, col, "Usage");
	mlx_string_put(mlx, win, x, y + 30, col, "Disable usage   space");
	mlx_string_put(mlx, win, x, y + 55, col, "Move            < ^ v >");
	mlx_string_put(mlx, win, x, y + 80, col, "Move            q w a d");
	mlx_string_put(mlx, win, x, y + 105, col, "Zoom            + -");
	mlx_string_put(mlx, win, x, y + 130, col, "Scale up        page up");
	mlx_string_put(mlx, win, x, y + 155, col, "Scale down      page down");
	mlx_string_put(mlx, win, x, y + 180, col, "Projection      p");
	mlx_string_put(mlx, win, x, y + 205, col, "Angle           q e");
	mlx_string_put(mlx, win, x, y + 230, col, ft_itoa(fdf->flag.angle_mod));
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
		while (j < 285)
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
