/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/05 21:19:07 by kbraum           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	if (argc != 2)
		return (printf("...\n"));
	data_init(argv[1]);
	t_figure	*fig = ((t_figure *)ft_lstlast(g_data.figures)->content);
	t_sphere	*sp = fig->param;
	t_canvas	*cnv = ((t_canvas *)g_data.cnvs->content);
	printf("%f\n", sp->radius);
	printf("%.f\n", cnv->cam.ang.z);
	printf("%.i\n", cnv->img.lnlen);
	for	(int i = 0; i < g_data.win.height; i++)
		for (int j = 0; j < g_data.win.width; j++)
			mlx_pixel_put(g_data.mlx, g_data.win.ptr, j, i,
				trgb_init(0, i * 256 / g_data.win.height, j * 256 / g_data.win.width,
				trgb_get_b(g_data.amb.color) * g_data.amb.ratio));
	mlx_loop(g_data.mlx);
}
