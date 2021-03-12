/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:23:35 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/12 21:58:12 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H
# define WIN_SIZE 512, 512

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

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

typedef	struct	s_dot
{	
	double		x;
	double		y;
	double		z;
}				t_dot;

typedef struct	s_cam
{
	t_dot		coord;
	t_dot		ang;
	int			fov;
}				t_cam;

t_win			win_init(void *mlx, char *line);
void			pixel_put(t_img *img, int x, int y, int color);
int				get_cx(int x, t_win *win);
int				get_cy(int y, t_win *win);
int				get_sx(int x, t_win *win);
int				get_sy(int y, t_win *win);
int				trgb_init(int t, int r, int g, int b);
int				trgb_get_t(int trgb);
int				trgb_get_r(int trgb);
int				trgb_get_g(int trgb);
int				trgb_get_b(int trgb);
int				color_add(int c1, int c2);
int				color_shade(int c, double shade);

#endif
