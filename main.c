/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:19:23 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/11 22:21:18 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_win	win_init(void* mlx, char *line)
{
	t_win	win;

	line++;
	win.w = ft_atoi(line);
	while (*line == ' ' || *line == '\t')
		line++;
	while (ft_isdigit(*line))
		line++;
	win.h = ft_atoi(line);
	win.ptr = mlx_new_window(mlx, win.w, win.h, "miniRT");
	return (win);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->lnlen + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
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

	if (argc != 2)
		return(printf("...\n"));
	data.mlx = mlx_init();
	rt_read(&data, argv[1]);
	mlx_loop(data.mlx);
	return (0);
}
