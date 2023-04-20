/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:16:59 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/20 12:19:52 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx.win_size.x = 1200;
	fdf->mlx.win_size.y = 800;
	fdf->flag.height = 3;
	fdf->flag.zoom = 3;
	fdf->flag.angle = 30;
	fdf->flag.z_angle = 45;
	fdf->flag.pos.x = 0;
	fdf->flag.pos.y = 0;
	get_color_theme(&fdf->disp);
}

void	show_leaks(void)
{
	system("leaks -q fdf");
}

int	main(const int ac, const char *av[])
{
	t_fdf	fdf;
	int		rtn;

	atexit(show_leaks);
	rtn = 1;
	if (ac == 2)
	{
		ft_bzero(&fdf, sizeof(t_fdf));
		if (parser(&fdf, av[1]))
		{
			init_fdf(&fdf);
			if (display_mlx_win(&fdf) == 0)
				rtn = 0;
		}
		else
		{
			free_map(&fdf.map);
			ft_printf("Error\n");
		}
	}
	else
		ft_printf("usage: %s map.fdf\n", av[0]);
	return (rtn);
}
