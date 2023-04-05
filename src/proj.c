/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:05:13 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/03 21:36:17 by psimarro         ###   ########.fr       */
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

t_vec2	isometric_projection(t_fdf *fdf, int x, int y, int z)
{
	t_vec2	rtn;
	int		angle;
	double	zoom;

	angle = ft_angle(fdf->flag.angle_mod);
	if (fdf->flag.zoom < 0)
		zoom = 1 / ((double) - (fdf->flag.zoom));
	else
		zoom = fdf->flag.zoom;
	x -= fdf->map.size.x / 2;
	y -= fdf->map.size.y / 2;
	x *= zoom;
	y *= zoom;
	z *= zoom * fdf->flag.height_mod / 10;
	rtn.x = cos(deg_to_rad(angle)) * y
		- cos(deg_to_rad(angle)) * x;
	rtn.y = -z * cos(deg_to_rad(angle * 2))
		+ sin(deg_to_rad(angle)) * x
		+ sin(deg_to_rad(angle)) * y;
	rtn.x += fdf->flag.pos.x;
	rtn.y += fdf->flag.pos.y;
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
	z *= zoom * fdf->flag.height_mod / 15;
	rtn.x = y + cos(deg_to_rad(fdf->flag.angle_mod)) * x;
	rtn.y = -z + sin(deg_to_rad(fdf->flag.angle_mod)) * x;
	rtn.x += fdf->flag.pos.x;
	rtn.y += fdf->flag.pos.y;
	return (rtn);
}
