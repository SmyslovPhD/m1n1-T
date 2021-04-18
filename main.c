/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/18 22:14:39 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	g_data;

void	minirt_exit(char *line)
{
	if (line)
	{
		printf("Error\n\"%s\"\n", line);
		free(line);
	}
	exit(1);
}

int		trace_ray(t_coord o, t_coord d, double start, double end)
{
	t_figure	*fig;

	fig = fig_closest(o, d, &start, end);
	if (fig == 0)
		return (0);
	return (li_intersec(fig, vec_sum(o, vec_scale(vec_init(o, d), start))));
}

int		main(int argc, char **argv)
{
	t_canvas	*cnv;
	t_coord		d;
	double		w;

	if (argc != 2)
		return (printf("no args\n"));
	data_init(argv[1]);
	cnv = (t_canvas *)(g_data.cnvs->content);
	w = tan(cnv->cam.fov * M_PI / 360);
	d.z = 1;
	for (int i = 0; i < g_data.win.h; i++)
	{
		d.y = (g_data.win.h - 2. * i) * w / g_data.win.w;
		for (int j = 0; j < g_data.win.w; j++)
		{
			d.x = w * (2. * j  / g_data.win.w - 1);
			mlx_pixel_put(g_data.mlx, g_data.win.ptr, j, i,
				trace_ray(cnv->cam.pos, vec_sum(cnv->cam.pos,
					vec_norm(coord_rot(rot_init(cnv->cam.ang), d))),
					1, INF));
		}
	}
	mlx_loop(g_data.mlx);
}
