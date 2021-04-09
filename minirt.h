/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:23:35 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/09 21:37:45 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# define INF 0x10000000
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

/*
**				vector_func
*/

typedef	t_coord	t_vector;

t_vector		vector_init(t_coord a, t_coord b);
t_vector		vector_scale(t_coord d, double c);
t_vector		vector_sum(t_vector a, t_vector b);
t_vector		vector_normalize(t_vector v);
double			vector_len(t_coord v);
double			dot_product(t_coord v1, t_coord v2);

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

void			camera_init(char *line);
void			image_init(t_list *cnvs);

/*
**				for scene
*/

typedef struct	s_amb
{
	double		ratio;
	int			color;
}				t_amb;

void			ambient_init(char *line);

typedef struct	s_light
{
	t_coord		pos;
	double		ratio;
	int			color;
}				t_light;

void			light_init(char *line);

typedef struct	s_figure
{
	char		id;
	void		*param;
	int			color;
}				t_figure;

typedef struct	s_sphere
{
	t_coord		pos;
	double		radius;
}				t_sphere;

void			sphere_init(t_figure *fig, char *line);
double			sphere_getdist(t_coord o, t_coord d, t_sphere *sp);

typedef struct	s_win
{
	void		*ptr;
	int			w;
	int			h;
}				t_win;

typedef	struct	s_data
{
	void		*mlx;
	t_win		win;
	t_amb		amb;
	t_list		*cnvs;
	t_list		*figures;
	t_list		*lights;
}				t_data;

extern t_data	g_data;
void			data_init(char *file);

/*
**				window_func
*/

void			window_init(char *line);

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

void			minirt_exit(char *line);

/*
**				figure_func
*/

void			figure_init(char *line);
double			figure_getdist(t_coord o, t_coord d, t_figure *fig);

int				color_add(int c1, int c2);
int				color_shade(int c, double *shade);

#endif
