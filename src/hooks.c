/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:00:23 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/02 09:41:35 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mlx_keycode.h"
#include "../inc/fdf.h"

static void	move(t_fdf *fdf, int keycode)
{
	if (keycode == SP_KEY)
		fdf->flag.disp_helper = !fdf->flag.disp_helper;
	if (keycode == P_KEY)
		fdf->flag.proj = !fdf->flag.proj;
	if (keycode == PUP_KEY)
		fdf->flag.height_mod++;
	if (keycode == PDOWN_KEY)
		fdf->flag.height_mod--;
	if (keycode == NKPL_KEY)
		fdf->flag.zoom += 2;
	if (keycode == NKMN_KEY)
		fdf->flag.zoom -= 2;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		fdf_exit(fdf);
	move(fdf, keycode);
	draw_win(fdf);
	return (0);
}

int	move_hook(int keycode, t_fdf *fdf)
{
	if (keycode == UP_KEY || keycode == W_KEY)
		fdf->flag.pos.y -= 20;
	if (keycode == DOWN_KEY || keycode == S_KEY)
		fdf->flag.pos.y += 20;
	if (keycode == LEFT_KEY || keycode == A_KEY)
		fdf->flag.pos.x -= 20;
	if (keycode == RIGHT_KEY || keycode == D_KEY)
		fdf->flag.pos.x += 20;
	if (keycode == CM_KEY || keycode == Q_KEY)
		fdf->flag.angle_mod += 3;
	if (keycode == PT_KEY || keycode == E_KEY)
		fdf->flag.angle_mod -= 3;
	draw_win(fdf);
	return (0);
}
