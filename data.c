/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:30:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/29 21:46:48 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void
		line_skip(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || line[i] == '\t'))
			minirt_exit(line);
		i++;
	}
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
			//TODO window
			printf("Win: %s\n", line);
		if (*line == 'A')
			//TODO ambient
			printf("Amb: %s\n", line);
		if (*line == 'c')
			//TODO camera
			printf("cam: %s\n", line);
		if (ft_strchr("s", *line))
			ft_lstadd_back(&g_data.figures, ft_lstnew(figure_init(line)));
		else if (*line == '\t' || *line == ' ')
			line_skip(line);
		free(line);
		n = get_next_line(fd, &line);
	}
}

void	data_init(char *file)
{
	int		fd;

	g_data.cnvs = 0;
	g_data.figures = 0;
	g_data.lights = 0;
	g_data.mlx = mlx_init();
	if (g_data.mlx == 0)
		minirt_exit(0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		minirt_exit(0);
	parse_file(fd);
	close (fd);
}
