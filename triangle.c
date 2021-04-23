/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:37:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/23 23:32:40 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	triangle_init(t_figure *fig, char *line)
{
	t_triangle	*tr;
	char		*s;
	
	fig->id = ID_TR;
	tr = (t_triangle *)malloc(sizeof(t_triangle));
	if (tr == 0)
		minirt_exit(line); //TODO errno?
	s = line + 2;
	fig->param = tr;
	if (read_coord(&s, &tr->p0) == 0
		|| read_coord(&s, &tr->p1) == 0
		|| read_coord(&s, &tr->p2) == 0
		|| read_color(&s, &fig->color) == 0)
		minirt_exit(line);
	//printf("x:%f\ny:%f\nz:%f\n\n", tr->p2.x, tr->p2.y, tr->p2.z);
	//if (tr->p0.z < tr->p1.z)
	//	ft_swap(&tr->p0, &tr->p1, sizeof(t_vec));
	//if (tr->p0.z < tr->p2.z)
	//	ft_swap(&tr->p0, &tr->p2, sizeof(t_vec));
	//if (tr->p1.z < tr->p2.z)
	//	ft_swap(&tr->p1, &tr->p2, sizeof(t_vec));
	tr->n = vec_cross(vec_init(tr->p0, tr->p1), vec_init(tr->p0, tr->p2));
	if (vec_len(tr->n) == 0)
		minirt_exit(line);
	tr->n = vec_norm(tr->n);
	tr->e01 = vec_init(tr->p0, tr->p1);
	tr->e12 = vec_init(tr->p1, tr->p2);
	tr->e20 = vec_init(tr->p2, tr->p0);
}

double	triangle_getdist(t_triangle *tr, t_coord o, t_vec od)
{
	double		dot;
	double		t;
	t_coord		p;

	dot = vec_dot(tr->n, od);
	if (fabs(dot) < T_MIN)
		return (INF);
	t = -vec_dot(vec_sum(o, tr->p0), tr->n) / dot;
	if (t < 0)
		return (INF);
	p = vec_sum(o, vec_scale(od, t));
	if (   vec_dot(tr->n, vec_cross(tr->e01, vec_init(tr->p0, p))) >= 0
		&& vec_dot(tr->n, vec_cross(tr->e12, vec_init(tr->p1, p))) >= 0
		&& vec_dot(tr->n, vec_cross(tr->e20, vec_init(tr->p2, p))) >= 0)
		return (t);
	return (INF);
}

t_vec	triangle_normal(t_triangle *tr, t_coord o, t_coord p)
{
	if (vec_dot(tr->n, vec_init(o, p)) >= T_MIN)
		return (vec_scale(tr->n, -1));
	return (tr->n);
}
