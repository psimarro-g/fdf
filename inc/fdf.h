/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:15:13 by psimarro          #+#    #+#             */
/*   Updated: 2023/04/19 21:35:12 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEFAULT_COLOR 0x00000000
# define TEXT_COLOR 0xFFFFFF

# include <stdbool.h>

typedef struct s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct s_point
{
	int			color;
	int			h;
}				t_point;

typedef struct s_map
{
	t_point		**map;
	t_vec2		size;
}				t_map;

typedef struct s_mlx
{
	void		*image;
	char		*buff;
	int			buf_wid;
	void		*window;
	void		*mlx;
	t_vec2		win_size;
	int			bpp;
	int			endian;
}				t_mlx;

typedef struct s_flag
{
	bool		disp_helper;
	int			height;
	t_vec2		pos;
	int			zoom;
	int			angle;
	int			exit_value;
	int			proj;
	int			z_angle;
}				t_flag;

typedef struct s_disp
{
	int				colortheme;
	int				bg_color;
	int				text_color;
	int				usage_color;
}				t_disp;

typedef struct s_fdf
{
	t_map		map;
	t_mlx		mlx;
	t_flag		flag;
	t_disp		disp;
}				t_fdf;

/*
** main
*/
void			init_fdf(t_fdf *fdf);
void			free_map(t_map *map);

/*
** mlx
*/
int				display_mlx_win(t_fdf *fdf);
int				fdf_exit(t_fdf *fdf);

/*
** hooks
*/
int				key_hook(int keycode, t_fdf *fdf);
int				move_hook(int keycode, t_fdf *fdf);

/*
** parser
*/
int				parser(t_fdf *fdf, const char *file_name);
int				add_line(t_fdf *fdf, char **arr);
int				check_line(t_fdf *fdf, char *line);

/*
** draw
*/
void			draw_win(t_fdf *fdf);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
void			ft_draw_line(t_mlx *mlx, t_pixel *p1, t_pixel *p2);
void			draw_fdf(t_fdf *fdf);

/*
** proj
*/
t_vec2			isometric_projection(t_fdf *fdf, int x, int y, int z);
t_vec2			parallel_projection(t_fdf *fdf, int x, int y, int z);
double			deg_to_rad(int degree);
int				ft_angle(int angle);

/*
** utils
*/
double			fpart(double x);
void			fdf_swap(int *a, int *b);

/*
** color
*/
void			get_color_theme(t_disp *disp);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

#endif