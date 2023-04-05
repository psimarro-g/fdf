/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:09:33 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/02 12:10:10 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdlib.h>

/*
** Verifies the validity of a point :
** Its z value, and the hexadecimal color value if one is specified.
*/

static char	*check_point(char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	while (*str != ' ' && *str != ',' && *str && *str != '\n')
	{
		if (*str < '0' || *str > '9')
			return (NULL);
		++str;
	}
	if (*str == ',')
	{
		if (*(str + 1) != '0' || *(str + 2) != 'x')
			return (NULL);
		str += 3;
		while (*str != ' ' && *str && *str != '\n')
		{
			if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
				&& (*str < 'A' || *str > 'F'))
				return (NULL);
			++str;
		}
	}
	return (str);
}

/*
** Verifies the validity of a line
*/

int	check_line(t_fdf *fdf, char *line)
{
	int		x;

	x = 0;
	while (*line && *line != '\n')
	{
		while (*line == ' ')
			++line;
		line = check_point(line);
		if (!line)
			return (0);
		++x;
	}
	if (fdf->map.size.x != 0 && x != fdf->map.size.x)
		return (0);
	fdf->map.size.x = x;
	return (1);
}
