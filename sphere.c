/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:22:28 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/08 23:45:29 by kbraum           ###   ########.fr       */
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

double	sphere_getdist(t_vector d, t_sphere *sp)
{
	double		disc;
	t_vector	co;
	double		k[3];

	co = vector_init(-sp->pos.x, -sp->pos.y, -sp->pos.z);
	k[0] = dot_product(d, d);
	k[1] = 2 * dot_product(d, co);
	k[2] = dot_product(co, co) - pow(sp->radius, 2);
	disc = pow(k[1], 2) - 4 * k[0] * k[2];
	if (disc < 0)
		return (INF);
	if (disc == 0)
		return (pow(k[1], 2) / (2 * k[0]));
	k[2] = (pow(k[1], 2) + sqrt(disc)) / (2 * k[0]);
	k[1] = (pow(k[1], 2) - sqrt(disc)) / (2 * k[0]);
	if (k[2] > k[1])
		return (k[2]);
	return (k[1]);
}
