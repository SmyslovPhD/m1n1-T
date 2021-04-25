/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:37:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/25 18:58:19 by kbraum           ###   ########.fr       */
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
	tr->n = vec_cross(vec_init(tr->p0, tr->p1), vec_init(tr->p0, tr->p2));
	if (vec_len(tr->n) == 0)
		minirt_exit(line);
}

double	triangle_getdist(t_triangle *tr, t_coord o, t_vec od)
{
	double	d;
	double	u;
	double	v;
	t_vec	tvec;
	t_vec	qvec;

//	static int k = 0;
//	printf("\ntr%i\n", k);
//	printf("p0:\t%f,\t%f,\t%f\n", tr->p0.x, tr->p0.y, tr->p0.z);
//	printf("p1:\t%f,\t%f,\t%f\n", tr->p1.x, tr->p1.y, tr->p1.z);
//	printf("p2:\t%f,\t%f,\t%f\n", tr->p2.x, tr->p2.y, tr->p2.z);
//	k = (k + 1) % 2;

    d = -vec_dot(od, tr->n);
    if (fabs(d) < T_MIN)
        return (INF);
    tvec = vec_init(tr->p0, o);
    u = vec_dot(tvec, vec_cross(od, vec_init(tr->p0, tr->p2))) / d;
    if (u < -T_MIN || u > 1 + T_MIN)
        return (INF);
    qvec = vec_cross(tvec, vec_init(tr->p0, tr->p1));
    v = vec_dot(od, qvec) / d;
    if (v < -T_MIN || u + v > 1 + T_MIN)
        return (INF);
    return vec_dot(vec_init(tr->p0, tr->p2), qvec) / d;
}

t_vec	triangle_normal(t_triangle *tr, t_coord o, t_coord p)
{
	if (vec_dot(tr->n, vec_init(o, p)) >= T_MIN)
		return (vec_scale(tr->n, -1));
	return (tr->n);
}
