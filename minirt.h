/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:23:35 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/14 21:34:34 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H
# define INF 0x100000000

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_dot
{
	int			i;
	int			j;
	int			color;
}				t_dot;

typedef	struct	s_coord
{	
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			lnlen;
	int			endian;
}				t_img;

typedef struct	s_win
{
	void		*ptr;
	int			w;
	int			h;
}				t_win;

typedef struct	s_data
{
	void		*mlx;
	t_win		win;
	t_img		img;
}				t_data;

typedef struct	s_cam
{
	t_coord		coord;
	t_coord		ang;
	int			fov;
}				t_cam;

typedef struct	s_sphere
{
	t_coord		p;
	double		r;
	int			color;
}				t_sphere;

t_win			win_init(void *mlx, char *line);
t_sphere		*sphere_init(t_coord center, double diameter, int color);
void			pixel_put(t_img *img, t_dot dot);
t_dot			get_coord_s(t_dot *dot, t_win *win);
int				get_cx(int x, t_win *win);
int				get_cy(int y, t_win *win);
int				trgb_init(int t, int r, int g, int b);
int				trgb_get_t(int trgb);
int				trgb_get_r(int trgb);
int				trgb_get_g(int trgb);
int				trgb_get_b(int trgb);
int				color_add(int c1, int c2);
int				color_shade(int c, double shade);

#endif
