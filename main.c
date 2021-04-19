/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/19 22:11:49 by kbraum           ###   ########.fr       */
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

int		trace_ray(t_coord o, t_vec d)
{
	t_figure	*fig;
	double		dist;

	dist = 1;
	fig = fig_closest(o, vec_sum(o, d), &dist, INF);
	if (fig == 0)
		return (0);
	d = vec_scale(d, dist);
	return (li_intersec(fig, vec_sum(o, d)));
}

void	render_image(t_canvas *cnv)
{
	t_coord		d;
	double		w;
	int			i;
	int			j;

	w = tan(cnv->cam.fov * M_PI / 360);
	i = g_data.win.h;
	while (i--)
	{
		d.z = 1;
		d.y = (g_data.win.h - 2. * i) * w / g_data.win.w;
		j = g_data.win.w;
		while (j--)
		{
			d.x = w * (2. * j  / g_data.win.w - 1);
			pixel_put(cnv->img, j, i, trace_ray(cnv->cam.pos,
				vec_norm(coord_rot(cnv->cam.rot, d))));
		}
	}
}

int		key_hook(int keycode, t_list **cnv)	//j
{
	if (keycode == 49)
	{
		*cnv = (*cnv)->next;
		if (*cnv == 0)
			*cnv = g_data.cnvs;
		mlx_put_image_to_window(g_data.mlx, g_data.win.ptr,
			((t_canvas *)(*cnv)->content)->img.ptr, 0, 0);
	}	
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*cnv;

	if (argc != 2)
		return (printf("no args\n"));
	data_init(argv[1]);
	ft_lstiter(g_data.cnvs, (void (*)(void *))render_image);
	cnv = g_data.cnvs;
	mlx_put_image_to_window(g_data.mlx, g_data.win.ptr,
		((t_canvas *)cnv->content)->img.ptr, 0, 0);
	mlx_key_hook(g_data.win.ptr, key_hook, &cnv);	//k
	mlx_loop(g_data.mlx);
}
