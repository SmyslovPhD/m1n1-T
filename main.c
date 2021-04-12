/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/12 22:38:51 by kbraum           ###   ########.fr       */
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

int		trace_ray(t_coord o, t_coord d)
{
	t_list		*elem;
	t_figure	*fig;
	double		dist;

	elem = g_data.figures;
	fig = figure_closest(o, d, &dist);
	if (fig == 0)
		return (0x5f5f5f);
	return (fig->color);
}

int		main(int argc, char **argv)
{
	t_canvas	*cnv;
	t_coord		d;
	double		w;
	double		h;

	if (argc != 2)
		return (printf("...\n"));
	data_init(argv[1]);
	cnv = (t_canvas *)(g_data.cnvs->content);
	w = tan(cnv->cam.fov * M_PI / 360);
	h = w * g_data.win.h / g_data.win.w;
	d.z = 1;
	for (int i = 0; i < g_data.win.h; i++)
	{
		d.y = -h + (2 * h * i / g_data.win.h);
		for (int j = 0; j < g_data.win.w; j++)
		{
			d.x = -w + (2 * w * j / g_data.win.w);
			mlx_pixel_put(g_data.mlx, g_data.win.ptr,
				j, i, trace_ray(cnv->cam.pos, d));
		}
	}
	printf("%f\n", h);
	mlx_loop(g_data.mlx);
}
