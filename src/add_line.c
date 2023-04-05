/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:12:22 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/03 20:03:40 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/fdf.h"
#include <limits.h>
#include <stdlib.h>

int	hex_to_int(char *hex)
{
	int		res;
	char	v;
	char	c;
	int		i;

	res = 0;
	i = 2;
	hex = ft_strchr(hex, ',');
	if (hex == NULL)
		res = DEFAULT_COLOR;
	else
	{
		while (hex[++i])
		{
			c = hex[i];
			v = (c & 0xF) + (c >> 6) | ((c >> 3) & 0x8);
			res = (res << 4) | (int) v;
		}
	}
	return (res);
}

static t_point	*parse_line(t_fdf *fdf, char **arr)
{
	int		i;
	t_point	*new;

	i = 0;
	new = ft_calloc(fdf->map.size.x, sizeof(t_point));
	if (!new)
		return (NULL);
	while (arr[i])
	{
		new[i].h = ft_atoi(arr[i]);
		new[i].color = hex_to_int(arr[i]);
		++i;
	}
	return (new);
}

int	add_line(t_fdf *fdf, char **arr)
{
	int		i;
	t_point	**tmp;

	tmp = ft_calloc(fdf->map.size.y, sizeof(t_point *));
	if (!tmp)
		return (0);
	i = fdf->map.size.y - 1;
	tmp[i] = parse_line(fdf, arr);
	if (!tmp[i])
		return (0);
	if (fdf->map.map)
	{
		while (--i >= 0)
			tmp[i] = fdf->map.map[i];
		free(fdf->map.map);
	}
	fdf->map.map = tmp;
	return (1);
}
