/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:19:23 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/12 22:37:09 by kbraum           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_data	data;
	t_cam	cam;

	if (argc != 2)
		return (printf("...\n"));
	data.mlx = mlx_init();
	rt_read(&data, argv[1]);
	cam = camera_init();
	data.img = image_init(&data);
	for (int i = 0; i < data.win.h; i++) {
		for(int j = 0; j < data.win.h; j++) {
			int color = trgb_init(0, 255, 255, 0);
			color = color_shade(color, (double)(i + j) / (data.win.h + data.win.w));
			pixel_put(&data.img, j, i, color);
		}
	}
	mlx_put_image_to_window(data.mlx, data.win.ptr, data.img.ptr, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
