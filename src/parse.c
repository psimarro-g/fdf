/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:29:03 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/03 19:15:04 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static void	free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		++i;
	}
	free(arr);
}

static int	pars_error(char *line, char **arr)
{
	ft_strdel(&line);
	if (arr)
		free_arr(arr);
	return (0);
}

static int	parser_aux(t_fdf *fdf, int fd)
{
	char	*line;
	char	**arr;

	line = get_next_line(fd);
	while (line)
	{
		if (!(check_line(fdf, line)))
			return (pars_error(line, NULL));
		arr = ft_split(line, ' ');
		if (!arr)
			return (pars_error(line, NULL));
		++fdf->map.size.y;
		if (!(add_line(fdf, arr)))
			return (pars_error(line, arr));
		free_arr(arr);
		arr = NULL;
		ft_strdel(&line);
		line = get_next_line(fd);
	}
	ft_strdel(&line);
	return (1);
}

int	parser(t_fdf *fdf, const char *file_name)
{
	int		fd;
	int		ret;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
	{
		fd = open(file_name, O_RDONLY);
		if (errno == EISDIR || fd < 0)
			return (0);
	}
	ret = parser_aux(fdf, fd);
	close(fd);
	return (ret);
}
