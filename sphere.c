/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:22:28 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/22 18:22:23 by kbraum           ###   ########.fr       */
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
		minirt_exit(ft_strdup(strerror(errno)));
	fig->param = (void*)sp;
	s = line + 2;
	if (read_coord(&s, &(sp->pos)) == 0
		|| read_double(&s, &(sp->radius)) == 0
		|| sp->radius <= 0
		|| read_color(&s, &(fig->color)) == 0)
		minirt_exit(line);
}

double	sphere_getdist(t_sphere *sp, t_coord o, t_vec od, double min)
{
	t_coord	co;
	t_vec	p;
	double	k[3];
	double	disc;
	double	t[2];

	co = vec_init(sp->pos, o);
	k[0] = vec_dot(od, od);
	k[1] = 2 * vec_dot(od, co);
	k[2] = vec_dot(co, co) - pow(sp->radius, 2);
	disc = k[1] * k[1] - 4 * k[0] * k[2];
	if (disc < 0) return (INF); if (disc == 0)
		return (-k[1] / (2 * k[0]));
	t[0] = (-k[1] - sqrt(disc)) / (2 * k[0]);
	t[1] = (-k[1] + sqrt(disc)) / (2 * k[0]);
	if (t[0] > t[1])
		ft_swap(t, t + 1, sizeof(double));
	p = vec_sum(o, vec_scale(od, t[0]));
	if (t[0] > min)
		return (t[0]);
	return (t[1]); }

t_vec	sphere_normal(t_sphere *sp, t_coord o, t_coord p)
{
	t_vec	n;

	n = vec_norm(vec_init(sp->pos, p));
	if (vec_dot(n, vec_init(o, p)) > 0)
		return (vec_scale(n, -1));
	return (n);
}
