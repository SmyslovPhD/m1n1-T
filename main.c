/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/08 23:46:12 by kbraum           ###   ########.fr       */
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

int		raytrace(t_coord o, t_coord d, double start, double end)
{
	t_list	*elem;
	int		color;
	double	dist;

	(void)o;
	elem = g_data.figures;
	d = vector_normalize(d);
	color = g_data.amb.color;
	while (elem)
	{
		dist = figure_getdist(d, ((t_figure *)elem->content));
		if (dist < end && dist > start)
		{
			end = dist;
			color = ((t_figure *)elem->content)->color;
		}
		elem = elem->next;
	}
	return (color);
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
			int color = raytrace(cnv->cam.pos, d, 1, INF);
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
