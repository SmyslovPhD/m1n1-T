/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:23:35 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/30 20:53:08 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# define INF 0x100000000
# define ID_SP 1

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef	struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef	t_coord	t_vector;

typedef struct	s_dot
{
	int			i;
	int			j;
}				t_dot;

/*
** 				for canvas
*/

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			lnlen;
	int			endian;
}				t_img;

typedef	struct	s_camera
{
	t_coord		pos;
	t_vector	ang;
	int			fov;
}				t_camera;

typedef	struct	s_canvas
{
	t_img		img;
	t_camera	cam;
}				t_canvas;

/*
**				for scene
*/

typedef struct	s_sphere
{
	t_coord		pos;
	double		radius;
}				t_sphere;

typedef struct	s_figure
{
	char		id;
	void		*param;
	int			color;
}				t_figure;

typedef struct	s_amb
{
	double		ratio;
	int			color;
}				t_amb;

typedef struct	s_scene
{
	t_list		*figures;
	t_list		*lights;
	//t_amb		*ambient;
}				t_scene;

typedef struct	s_win
{
	void		*ptr;
	int			width;
	int			height;
}				t_win;

typedef	struct	s_data
{
	void		*mlx;
	t_win		win;
	t_list		*cnvs;
	t_list		*figures;
	t_list		*lights;
	//t_amb		*ambient;
}				t_data;

extern t_data	g_data;
void			data_init(char *file);

/*
**				window_func
*/

void			window_init(char *line);

/*
**				vector_func
*/

t_coord			vector_init(double x, double y, double z);
t_coord			get_vector(t_coord start, t_coord end);
t_vector		vector_normalize(t_vector v);
double			vector_len(t_coord v);
double			dot_product(t_coord v1, t_coord v2);

/*
**				trgb_func
*/

int				trgb_init(int t, int r, int g, int b);
int				trgb_get_t(int trgb);
int				trgb_get_r(int trgb);
int				trgb_get_g(int trgb);
int				trgb_get_b(int trgb);

/*
**				read_func
*/

int				read_coord(char **line, t_coord *dot);
int				read_vector(char **line, t_vector *v);
int				read_color(char **line, int *color);
int				read_double(char **line, double *j);

/*
**				window_func
*/

void			minirt_exit(char *line);

/*
**				figure_fu
line++;
g_data.win*/

void			*figure_init(char *line);

/*
**				sphere_func
*/

void			sphere_init(t_figure *fig, char *line);

#endif
