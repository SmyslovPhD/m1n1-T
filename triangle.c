/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:37:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/25 00:42:55 by kbraum           ###   ########.fr       */
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
	//if (tr->p0.z < tr->p1.z)
	//	ft_swap(&tr->p0, &tr->p1, sizeof(t_vec));
	//if (tr->p0.z < tr->p2.z)
	//	ft_swap(&tr->p0, &tr->p2, sizeof(t_vec));
	//if (tr->p1.z < tr->p2.z)
	//	ft_swap(&tr->p1, &tr->p2, sizeof(t_vec));
	
	tr->n = vec_norm(tr->n);
	tr->e1 = vec_init(tr->p0, tr->p1);
	tr->e2 = vec_init(tr->p0, tr->p2);
	tr->n = vec_cross(tr->e1, tr->e2);
	if (vec_len(tr->n) == 0)
		minirt_exit(line);
}

double	triangle_getdist(t_triangle *tr, t_coord o, t_vec od)
{
    float	det = - vec_dot(od, tr->n);
    if (fabs(det) < 1e-8)
        return (INF);

    t_vec	pvec = vec_cross(od, tr->e2);

    float	inv_det = 1 / det;
    t_vec	tvec = vec_init(tr->p0, o);
    float	u = vec_dot(tvec, pvec) * inv_det;
    if (u < 0 || u > 1)
        return (INF);

    t_vec qvec = vec_cross(tvec, tr->e1);
    float v = vec_dot(od, qvec) * inv_det;
    if (v < 0 || u + v > 1) {
        return 0;
    }
    return vec_dot(tr->e2, qvec) * inv_det;
}

t_vec	triangle_normal(t_triangle *tr, t_coord o, t_coord p)
{
	if (vec_dot(tr->n, vec_init(o, p)) >= T_MIN)
		return (vec_scale(tr->n, -1));
	return (tr->n);
}
