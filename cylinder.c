/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:11:56 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/27 21:32:07 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_proj(t_vec vec, t_vec onto)
{
	return (vec_scale(onto, vec_dot(vec, onto) / vec_dot(onto, onto)));
}

void	cylinder_init(t_figure *fig, char *line)
{
	t_cylinder	*cy;
	char		*s;

	fig->id = ID_CY;
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cy == 0)
		minirt_exit(line);
	s = line + 2;
	fig->param = cy;
	if (read_coord(&s, &cy->pos) == 0
		|| read_vec(&s, &cy->vec) == 0
		|| read_double(&s, &cy->h) == 0
		|| read_double(&s, &cy->r) == 0
		|| cy->h <= 0
		|| cy->r <= 0
		|| read_color(&s, &fig->color) == 0)
		minirt_exit(line);
	cy->r /= 2;
	cy->par = vec_proj(cy->pos, cy->vec);
	cy->perp = vec_init(cy->par, cy->pos);
}

double	cylinder_getdist(t_cylinder *cy, t_coord o, t_vec od, double min)
{
	t_sphere	sp;
	t_vec		p;
	t_vec		o_par;
	t_vec		od_par;
	double		t;

	o_par = vec_proj(o, cy->vec);
	od_par = vec_proj(od, cy->vec);
	sp.pos = cy->perp;
	sp.radius = cy->r;
	t = sphere_getdist(&sp, vec_init(o_par, o), vec_init(od_par, od), min);
	p = vec_sum(o_par, vec_scale(od_par, t));
	if (vec_len(vec_init(cy->par, p)) < (cy->h / 2 + T_MIN))
		return (t);
	t = sphere_getdist(&sp, vec_init(o_par, o), vec_init(od_par, od), t);
	p = vec_sum(o_par, vec_scale(od_par, t));
	if (vec_len(vec_init(cy->par, p)) < (cy->h / 2 + T_MIN))
		return (t);
	return (INF);
}

t_vec	cylinder_normal(t_cylinder *cy, t_coord o, t_coord p)
{
	t_vec	n;
	t_vec	p0p;

	p0p = vec_init(cy->pos, p);
	n = vec_norm(vec_init(vec_proj(p0p, cy->vec), p0p));
	if (vec_dot(n, vec_init(o, p)) > T_MIN)
		return (vec_scale(n, -1));
	return (n);
}
