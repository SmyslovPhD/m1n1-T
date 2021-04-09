/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:22:28 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/09 17:43:35 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sphere_init(t_figure *fig, char *line)
{
	t_sphere	*sp;
	char		*s;

	fig->id = ID_SP;
	sp = (t_sphere*)malloc(sizeof(t_sphere));
	if (sp == 0)
		minirt_exit(line);
	fig->param = (void*)sp;
	s = line + 2;
	if (read_coord(&s, &(sp->pos)) == 0
		|| read_double(&s, &(sp->radius)) == 0
		|| sp->radius < 0
		|| read_color(&s, &(fig->color)) == 0)
		minirt_exit(line);
}

double	sphere_getdist(t_coord o, t_coord d, t_sphere *sp)
{
	t_vector	od;
	t_vector	co;
	double		k[6];

	od = vector_init(o, d);
	co = vector_init(sp->pos, o);
	k[1] = dot_product(od, od);
	k[2] = 2 * dot_product(od, co);
	k[3] = dot_product(co, co) - pow(sp->radius, 2);
	k[0] = k[2] * k[2] - 4 * k[1] * k[3];
	if (k[0] < 0)
		return (INF);
	if (k[0] == 0)
		return (-k[2] / (2 * k[1]));
	k[4] = (-k[2] + sqrt(k[0])) / (2 * k[1]);
	k[5] = (-k[2] - sqrt(k[0])) / (2 * k[1]);
	if (k[4] > k[5])
	{
		k[3] = k[4];
		k[4] = k[5];
		k[5] = k[3];
	}
	if (k[4] >= vector_len(od))
		return (k[4]);
	return (k[5]);
}
