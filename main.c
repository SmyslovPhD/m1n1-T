/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/30 20:55:14 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	g_data;

void	minirt_exit(char *line)
{
	if (line)
	{
		ft_printf("Error\non line: \"%s\"\n", line);
		free(line);
	}
	exit(1);
}

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	if (argc != 2)
		return (printf("...\n"));
	data_init(argv[1]);
	t_figure	*fig = (t_figure*)(g_data.figures->content);
	t_sphere	*sp = fig->param;
	printf("%f\n", sp->radius);
	mlx_loop(g_data.mlx);
}
