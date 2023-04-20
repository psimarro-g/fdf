/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:05:13 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/20 14:17:24 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../inc/fdf.h"

double	deg_to_rad(int degree)
{
	return (degree * 3.14159265F / 180.0F);
}

int	ft_angle(int angle)
{
	int	rtn;

	rtn = angle;
	if (angle > 45)
		rtn = 45;
	else if (angle < -45)
		rtn = -45;
	return (rtn);
}

void	ft_z_angle(t_fdf *fdf)
{
	if (fdf->flag.z_angle > 177)
		fdf->flag.z_angle = 177;
	else if (fdf->flag.z_angle < 0)
		fdf->flag.z_angle = 0;
}

t_vec2	isometric_projection(t_fdf *fdf, int x, int y, int z)
{
	t_vec2	rtn;
	int		angle;
	double	zoom;

	angle = ft_angle(fdf->flag.angle);
	ft_z_angle(fdf);
	if (fdf->flag.zoom < 0)
		zoom = 1 / ((double) - (fdf->flag.zoom));
	else
		zoom = fdf->flag.zoom;
	x -= fdf->map.size.x / 2;
	y -= fdf->map.size.y / 2;
	x *= zoom;
	y *= zoom;
	z *= zoom * fdf->flag.height / 10;
	rtn.x = cos(deg_to_rad(fdf->flag.z_angle)) * x
		- sin(deg_to_rad(fdf->flag.z_angle)) * y;
	rtn.y = sin(deg_to_rad(angle)) * sin(deg_to_rad(fdf->flag.z_angle)) * x
		- cos(deg_to_rad(angle)) * z
		+ sin(deg_to_rad(angle)) * cos(deg_to_rad(fdf->flag.z_angle)) * y;
	rtn.x += (fdf->flag.pos.x * zoom) + fdf->mlx.win_size.x / 2;
	rtn.y += (fdf->flag.pos.y * zoom) + fdf->mlx.win_size.y / 2;
	return (rtn);
}

t_vec2	parallel_projection(t_fdf *fdf, int x, int y, int z)
{
	t_vec2	rtn;
	double	zoom;

	x -= fdf->map.size.x / 4;
	y -= fdf->map.size.y / 2;
	if (fdf->flag.zoom < 0)
		zoom = 1 / (double)-(fdf->flag.zoom);
	else
		zoom = fdf->flag.zoom;
	x *= zoom;
	y *= zoom;
	z *= zoom * fdf->flag.height / 15;
	rtn.x = y + cos(deg_to_rad(fdf->flag.angle)) * x;
	rtn.y = -z + sin(deg_to_rad(fdf->flag.angle)) * x;
	rtn.x += (fdf->flag.pos.x * zoom) + fdf->mlx.win_size.x / 2;
	rtn.y += (fdf->flag.pos.y * zoom) + fdf->mlx.win_size.y / 2;
	return (rtn);
}
