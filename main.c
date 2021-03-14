/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:19:23 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/14 21:46:24 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	camera_init(void)
{
	t_cam	cam;

	cam.coord.x = 0;
	cam.coord.y = 0;
	cam.coord.z = 0;
	cam.ang.x = 0;
	cam.ang.y = 0;
	cam.ang.z = 1;
	cam.fov = 60;

	return (cam);
}

t_img	image_init(t_data *data)
{
	t_img	img;
	
	img.ptr = mlx_new_image(data->mlx, data->win.w, data->win.h);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.lnlen, &img.endian);
	return (img);
}

void	rt_read(t_data *data, char *file)
{
	int		fd;
	char	*line;

	(void)data;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line == 'R')
			data->win = win_init(data->mlx, line);
		free(line);
	}
	close(fd);
}

t_coord	get_vektor(t_coord start, t_coord end)
{
	t_coord		v;

	v.x = end.x - start.x;
	v.y = end.y - start.y;
	v.z = end.z - start.z;
	return (v);
}

double	vektor_len(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	dot_product(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_coord	canvas_to_viewpoint(t_win win, t_dot dot)
{
	t_coord	d;

	d.x = dot.x / win.w;
	d.y = dot.x / win.h;
	d.z = 1;

	return (d);
}

t_coord coord_init(double x, double y, double z)
{
	t_coord		p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_list	*test(void)
{
	t_list		*lst;
	t_coord		p;

	p = coord_init(0, -1, 4);
	ft_lstadd_back(&lst, ft_lstnew(sphere_init(p, 1, 0xff0000)));
	p = coord_init(-2, 0, 5);
	ft_lstadd_back(&lst, ft_lstnew(sphere_init(p, 1, 0xff00)));
	p = coord_init(2, 0, 5);
	ft_lstadd_back(&lst, ft_lstnew(sphere_init(p, 1, 0xff)));
	return (lst);
}

int		trace_ray(t_cam o, t_coord d, double start, double end)
{
	t_list		*lst;
	t_list		*elem;
	double		dist;
	int			color;

	dist = end;
	color = trgb_init(0, 0, 0, 0);
	elem = lst = test();
	while (elem)
	{
		color = shere_intersec(o, d, elem->content);
		elem = elem->next;
	}
	ft_lstclear(&lst, free);
	return (color);
}

int		main(int argc, char **argv)
{
	t_data	data;
	t_cam	cam;
	t_dot	dot;

	if (argc != 2)
		return (printf("...\n"));
	data.mlx = mlx_init();
	rt_read(&data, argv[1]);
	data.img = image_init(&data);
	dot.i = -data.win.h / 2 ;
	cam = camera_init();
	while (dot.i < data.win.h / 2)
	{
		dot.j = -data.win.w / 2;
		while (dot.j < data.win.w / 2)
		{
			dot.color = trace_ray(cam, canvas_to_viewpoint(data.win, dot), 1, INF);
			pixel_put(&data.img, get_coord_s(&dot, &data.win));
			dot.j++;
		}
		dot.i++;
	}
	mlx_put_image_to_window(data.mlx, data.win.ptr, data.img.ptr, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
