/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:49:50 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/03 20:07:40 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../Libft/inc/libft.h"
#include "../inc/fdf.h"

static void	ft_plot(t_mlx *mlx, t_pixel p, double fade)
{
	unsigned int	c;
	unsigned int	shift;

	shift = (int)(0xFF * fade);
	c = (p.color | (shift << 24));
	put_pixel(mlx, p.x, p.y, c);
}

static int	find_color_of_my_stupid_pixel(t_pixel *p1, t_pixel *p2, int x)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	dist;

	dist = p2->x - p1->x;
	t = get_t(p1->color) + (((get_t(p2->color) - get_t(p1->color)) * x) / dist);
	r = get_r(p1->color) + (((get_r(p2->color) - get_r(p1->color)) * x) / dist);
	g = get_g(p1->color) + (((get_g(p2->color) - get_g(p1->color)) * x) / dist);
	b = get_b(p1->color) + (((get_b(p2->color) - get_b(p1->color)) * x) / dist);
	return (t << 24 | r << 16 | g << 8 | b);
}

static double	get_grad(t_pixel *p1, t_pixel *p2)
{
	double	grad;

	if (p2->x - p1->x)
		grad = (double)(p2->y - p1->y) / (double)(p2->x - p1->x);
	else
		grad = 1;
	return (grad);
}

static void	ft_drawline(int steep, t_mlx *mlx, t_pixel *p1, t_pixel *p2)
{
	int		color;
	int		x;
	double	y;
	double	grad;

	x = p1->x;
	y = (double)p1->y;
	grad = get_grad(p1, p2);
	while (x < p2->x)
	{
		color = find_color_of_my_stupid_pixel(p1, p2, x - p1->x);
		if (steep)
		{
			ft_plot(mlx, (t_pixel){(int)y - 1, x, color}, fpart(y));
			ft_plot(mlx, (t_pixel){(int)y, x, color}, 1 - fpart(y));
		}
		else
		{
			ft_plot(mlx, (t_pixel){x, (int)y - 1, color}, fpart(y));
			ft_plot(mlx, (t_pixel){x, (int)y, color}, 1 - fpart(y));
		}
		y += grad;
		++x;
	}
}

void	ft_draw_line(t_mlx *mlx, t_pixel *p1, t_pixel *p2)
{
	int	steep;

	steep = abs(p2->y - p1->y) > abs(p2->x - p1->x);
	if (steep)
	{
		fdf_swap(&p1->x, &p1->y);
		fdf_swap(&p2->x, &p2->y);
	}
	if (p1->x > p2->x)
	{
		fdf_swap(&p1->x, &p2->x);
		fdf_swap(&p1->y, &p2->y);
		fdf_swap(&p1->color, &p2->color);
	}
	ft_drawline(steep, mlx, p1, p2);
}
