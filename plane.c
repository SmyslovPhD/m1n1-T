/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:19 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/22 20:56:36 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	plane_init(t_figure *fig, char *line)
{
	t_plane	*pl;
	char	*s;
	
	fig->id = ID_PL;
	pl = (t_plane *)malloc(sizeof(t_plane));
	if (pl == 0)
		minirt_exit(line); //TODO errno?
	s = line + 2;
	fig->param = pl;
	if (read_coord(&s, &pl->pos) == 0
		|| read_vec(&s, &pl->n) == 0
		|| read_color(&s, &fig->color) == 0)
		minirt_exit(line);
}

double	plane_getdist(t_plane *pl, t_coord o, t_vec od)
{
	double	t;
	double	dot
	
	dot = vec_dot(pl->n, od);
	if (fabs(dot) < T_MIN)
		return (INF);
	t = vec_dot(vec_init(o, pl->pos), pl->n) / dot;
	return (t);
}

t_vec	plane_normal(t_plane *pl, t_coord o, t_coord p)
{
	if (vec_dot(pl->n, vec_init(o, p)) >= 0)
		return (vec_scale(pl->n, -1));
	return (pl->n);
}
