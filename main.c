/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/24 21:35:01 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_exit(char *line)
{
	if (line)
		free(line);
	ft_printf("Error\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	char		*s;
	t_figure	*fig;

	(void)argv;
	(void)argc;
	s = ft_strdup("sp 0,1,0 1120 121,122,1222   ");
	fig = (t_figure*)figure_init(s);
	t_sphere *sp = (t_sphere*)(fig->param);
	printf("\n");
	printf("sp id = %d \ncoords: %.3f,%.3f,%.3f\n", fig->id, sp->pos.x, sp->pos.y, sp->pos.z);
	printf("rad: %.3f\n", sp->radius);
	printf("colors: %d, %d, %d\n", trgb_get_r(fig->color),
			trgb_get_g(fig->color), trgb_get_b(fig->color));
	free(sp);
	free(fig);
	free(s);
}
