/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:22:28 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/14 17:58:19 by kbraum           ###   ########.fr       */
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
	t_vec	od;
	t_vec	co;
	double	t[2];
	double	k[3];
	double	disc;

	od = vec_init(o, d);
	co = vec_init(sp->pos, o);
	k[0] = vec_dot(od, od);
	k[1] = 2 * vec_dot(od, co);
	k[2] = vec_dot(co, co) - pow(sp->radius, 2);
	disc = k[1] * k[1] - 4 * k[0] * k[2];
	if (disc < 0)
		return (INF);
	if (disc == 0)
		return (-k[1] / (2 * k[0]));
	t[0] = (-k[1] + sqrt(disc)) / (2 * k[0]);
	t[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
	if (t[0] > t[1])
	{
		k[2] = t[0];
		t[0] = t[1];
		t[1] = k[2];
	}
	if (t[0] >= vec_len(od))
		return (t[0]);
	return (t[1]);
}

t_vec	sphere_norm(t_sphere *sp, t_coord p)
{
	return (vec_norm(vec_init(sp->pos, p)));
}
