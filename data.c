/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:30:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/27 21:56:45 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void
	line_skip(char *line)
{
	char	*s;

	s = line;
	while (*s)
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
		if (ft_strchr(" \t", *line))
			line_skip(line);
		else if (*line == 'R')
			window_init(line);
		else if (*line == 'A')
			ambient_init(line);
		else if (*line == 'l')
			light_init(line);
		else if (*line == 'c' && line[1] != 'y')
			camera_init(line);
		else if (ft_strchr("sptc", *line))
			figure_init(line);
		free(line);
		n = get_next_line(fd, &line);
	}
}

void	data_init(char *file)
{
	int		fd;

	if (ft_strncmp(file + ft_strlen(file) - 3, ".rt", 3) != 0)
		minirt_exit(ft_strdup("It's not an .rt file"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		minirt_exit(strdup("Can't open file"));
	parse_file(fd);
	close(fd);
	if (g_data.cnvs == 0)
		minirt_exit(ft_strdup("NO CAMS"));
	image_init();
}
