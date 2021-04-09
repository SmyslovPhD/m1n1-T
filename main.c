/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/09 22:20:39 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	g_data;

void	minirt_exit(char *line)
{
	if (line)
	{
		ft_printf("Error\n\"%s\"\n", line);
		free(line);
	}
	exit(1);
}

int		compute_light(t_figure *fig, t_coord p)
{
	double	intence[3];
	t_list	*elem;
	t_light *li;
	t_vector cp;
	t_vector n;

	cp = vector_init(((t_sphere *)fig->param)->pos, p);
	elem = g_data.lights;
	intence[0] = g_data.amb.ratio * trgb_get_r(g_data.amb.color) / 256;
	intence[1] = g_data.amb.ratio * trgb_get_g(g_data.amb.color) / 256;
	intence[2] = g_data.amb.ratio * trgb_get_b(g_data.amb.color) / 256;
	while (elem)
	{
		li = elem->content;
		n = vector_init(p, li->pos);
		if (dot_product(cp, n) > 0)
		{
			intence[0] += ((li->ratio * trgb_get_r(li->color) / 256))
				* dot_product(cp, n) / vector_len(n) / vector_len(cp);
			intence[1] += ((li->ratio * trgb_get_g(li->color) / 256))
				* dot_product(cp, n) / vector_len(n) / vector_len(cp);
			intence[2] += ((li->ratio * trgb_get_b(li->color) / 256))
				* dot_product(cp, n) / vector_len(n) / vector_len(cp);
		}
		elem = elem->next;
	}
	return (color_shade(fig->color, intence));
}

int		trace_ray(t_coord o, t_coord d, double start, double end)
{
	t_list		*elem;
	t_figure	*closest_fig;
	double		dist;

	elem = g_data.figures;
	closest_fig = 0;
	while (elem)
	{
		dist = figure_getdist(o, d, ((t_figure *)elem->content));
		if (dist < end && dist >= start)
		{
			end = dist;
			closest_fig = elem->content;
		}
		elem = elem->next;
	}
	if (closest_fig)
		return (compute_light(closest_fig,
			vector_init(o , vector_scale(d, end))));
	return (0x0f0f0f);
}

int		main(int argc, char **argv)
{
	t_canvas	*cnv;
	t_coord		d;

	if (argc != 2)
		return (printf("...\n"));
	data_init(argv[1]);
	cnv = (t_canvas *)(g_data.cnvs->content);
	d.z = 1;
	d.y = .5;
	while (d.y > -.5)
	{
		d.x = -0.5;
		while (d.x < .5)
		{
			int color = trace_ray(cnv->cam.pos, d, vector_len(d), INF);
			mlx_pixel_put(g_data.mlx, g_data.win.ptr,
				(d.x + .5) * g_data.win.w,
				(.5 - d.y) * g_data.win.h,
				color);
			d.x += 1.0 / g_data.win.w;
		}
		d.y -= 1.0 / g_data.win.h;
	}
	mlx_loop(g_data.mlx);
}
