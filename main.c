/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 22:35:58 by kbraum           ###   ########.fr       */
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
	t_figure	fig;

	(void)argv;
	(void)argc;
	s = ft_strdup("sp 0,1,0 120 121,122,12");
	sphere_init(&fig, s);
	t_sphere	*sp = (t_sphere*)(fig.param);
	printf("\n");

	printf("sp coords: %.3f,%.3f,%.3f\n", sp->pos.x, sp->pos.y, sp->pos.z);
	printf("sp rad: %.3f\n", sp->radius);
	printf("sp colors: %d, %d, %d\n", trgb_get_r(fig.color),
			trgb_get_g(fig.color), trgb_get_b(fig.color));
	free(sp);
	free(s);
}
