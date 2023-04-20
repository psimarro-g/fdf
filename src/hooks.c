/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:00:23 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/19 21:40:25 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/keycode.h"
#include "../inc/fdf.h"

static void	get_flags(t_fdf *fdf, int keycode)
{
	if (keycode == SP_KEY)
		fdf->flag.disp_helper = !fdf->flag.disp_helper;
	else if (keycode == P_KEY)
		fdf->flag.proj = !fdf->flag.proj;
	else if (keycode == NKPL_KEY)
		fdf->flag.zoom += 2;
	else if (keycode == NKMN_KEY)
		fdf->flag.zoom -= 2;
	else if (keycode == PUP_KEY)
		fdf->flag.height++;
	else if (keycode == PDOWN_KEY)
		fdf->flag.height--;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		fdf_exit(fdf);
	get_flags(fdf, keycode);
	draw_win(fdf);
	return (0);
}

int	move_hook(int keycode, t_fdf *fdf)
{
	if (keycode == UP_KEY || keycode == W_KEY)
		fdf->flag.pos.y += 10;
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		fdf->flag.pos.y -= 10;
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		fdf->flag.pos.x += 10;
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		fdf->flag.pos.x -= 10;
	else if (keycode == Q_KEY)
		fdf->flag.angle += 3;
	else if (keycode == E_KEY)
		fdf->flag.angle -= 3;
	else if (keycode == Z_KEY)
		fdf->flag.z_angle += 3;
	else if (keycode == C_KEY)
		fdf->flag.z_angle -= 3;
	draw_win(fdf);
	return (0);
}
