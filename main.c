/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:19:23 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/12 20:04:27 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		return (printf("...\n"));
	data.mlx = mlx_init();
	rt_read(&data, argv[1]);
	mlx_loop(data.mlx);
	return (0);
}
