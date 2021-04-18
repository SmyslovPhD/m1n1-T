/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:23:35 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/18 19:41:24 by kbraum           ###   ########.fr       */
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

typedef struct s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

/*
**				vec_func
*/

typedef t_coord	t_vec;

t_vec			vec_init(t_coord a, t_coord b);
t_vec			vec_scale(t_coord d, double c);
t_vec			vec_sum(t_vec a, t_vec b);
t_vec			vec_norm(t_vec v);
double			vec_len(t_coord v);
double			vec_dot(t_coord v1, t_coord v2);

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

typedef struct	s_rot
{
	t_vec		x;
	t_vec		y;
	t_vec		z;
}				t_rot;

typedef	struct	s_camera
{
	t_coord		pos;
	t_vec		ang;
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

typedef struct	s_figure
{
	char		id;
	void		*param;
	int			color;
}				t_figure;

void			figure_init(char *line);
double			figure_getdist(t_figure *fig, t_coord o, t_coord d);
t_vec		fig_norm(t_figure *fig, t_coord p);
t_figure		*fig_closest(t_coord o, t_coord d, double *start, double end);

typedef struct	s_sphere
{
	t_coord		pos;
	double		radius;
}				t_sphere;

void			sphere_init(t_figure *fig, char *line);
double			sphere_getdist(t_coord o, t_coord d, t_sphere *sp);
t_vec		sphere_norm(t_sphere *sp, t_coord p);

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
int				li_intersec(t_figure *fig, t_vec p);

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
int				read_vec(char **line, t_vec *v);
int				read_color(char **line, int *color);
int				read_double(char **line, double *j);

void			minirt_exit(char *line);

/*
**				figure_func
*/

int				color_add(int c1, int c2);
int				color_shade(int c, double *shade);

t_coord			coord_rot(const t_rot rot, const t_coord p);
t_rot			rot_init(const t_vec v);

#endif
