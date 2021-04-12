/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:30:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/12 19:23:34 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void
		line_skip(char *line)
{
	char	*s;

	s = line;
	while (s)
		if (ft_strchr(" \t", *(s++)) == 0)
			minirt_exit(line);
}

void	parse_file(int fd)
{
	int		n;
	char	*line;

	n = get_next_line(fd, &line);
	while (n)
	{
		if (n < 0)
			minirt_exit(line);
		if (*line == 'R')
			window_init(line);
		if (*line == 'A')
			ambient_init(line);
		if (*line == 'l')
			light_init(line);
		if (*line == 'c')
			camera_init(line);
		if (*line == 's')
			figure_init(line);
		if (*line == ' ' || *line == '\t')
			line_skip(line);
		free(line);
		n = get_next_line(fd, &line);
	}
}

void	data_init(char *file)
{
	int		fd;

	//TODO set all pointer to NULL
	fd = open(file, O_RDONLY);
	if (fd < 0)
		minirt_exit(0);
	parse_file(fd);
	close(fd);
	g_data.mlx = mlx_init();
	if (g_data.mlx == 0)
		minirt_exit(ft_strdup("mlx error!"));
	g_data.win.ptr = mlx_new_window(g_data.mlx,
		g_data.win.w, g_data.win.h, "miniRT");
	image_init(g_data.cnvs);
}
