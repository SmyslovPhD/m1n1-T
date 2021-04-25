/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:33:10 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/25 16:06:45 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_init(char *line)
{
	t_canvas	*cnv;
	t_camera	*cam;
	t_vec		ang;
	char		*s;

	cnv = (t_canvas *)malloc(sizeof(t_canvas));
	if (cnv == 0)
		minirt_exit(line);
	cam = &(cnv->cam);
	s = line + 1;
	if (read_coord(&s, &cam->pos) == 0
		|| read_vec(&s, &ang) == 0
		|| read_double(&s, &cam->fov) == 0
		|| cam->fov < 60 || cam->fov > 180) //TODO fov in [90; 180];
		minirt_exit(line);
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s != '\0')
		minirt_exit(line);
	cam->rot = rot_init(ang);
	ft_lstadd_back(&g_data.cnvs, ft_lstnew(cnv));
}

void	image_init(void)
{
	t_img		*img;
	t_win		*win;
	t_list		*elem;

	win = &g_data.win;
	elem = g_data.cnvs;
	while (elem)
	{
		img = &((t_canvas *)elem->content)->img;
		img->ptr = mlx_new_image(g_data.mlx, win->w, win->h);
		img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->lnlen, &img->endian);
		elem = elem->next;
	}
}

void	pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.lnlen + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

int		trace_ray(t_coord o, t_vec od)
{
	t_figure	*fig;
	double		dist;

	dist = 1;
	fig = fig_closest(o, od, &dist, INF);
	if (fig == 0)
		return (0);
	od = vec_scale(od, dist);
	return (li_intersec(fig, o, vec_sum(o, od)));
}

void	image_render(t_canvas *cnv)
{
	t_vec		od;
	double		w;
	int			i;
	int			j;

	w = tan(cnv->cam.fov * M_PI / 360);
	i = g_data.win.h;
	while (i--)
	{
		od.z = 1;
		od.y = (g_data.win.h - 2. * i) * w / g_data.win.w;
		j = g_data.win.w;
		while (j--)
		{
			od.x = w * (2. * j  / g_data.win.w - 1);
			pixel_put(cnv->img, j, i, trace_ray(cnv->cam.pos,
				rotate(cnv->cam.rot, vec_norm(od))));
		}
	}
}
