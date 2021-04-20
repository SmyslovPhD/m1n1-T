/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:19 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/20 23:36:33 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	square_init(t_figure *fig, char *line)
{
	t_square	*sq;
	char		*s;
	
	fig->id = ID_SQ;
	sq = (t_square *)malloc(sizeof(t_square));
	if (sq == 0)
		minirt_exit(line); //TODO errno?
	s = line + 2;
	fig->param = sq;
	if (read_coord(&s, &sq->pos) == 0
		|| read_vec(&s, &sq->n) == 0
		|| read_double(&s, &sq->size) == 0
		|| read_color(&s, &fig->color) == 0)
		minirt_exit(line);
}

double	square_getdist(t_square *sq, t_coord o, t_coord d)
{
	double	t;
	t_vec	od;

	od = vec_init(o, d);
	if (fabs(vec_dot(sq->n, od)) < T_MIN)
		return (INF);
	t = vec_dot(vec_init(o, sq->pos), sq->n) / vec_dot(od, sq->n);
	if (vec_len(vec_init(sq->pos, vec_sum(o, vec_scale(od, t))))
		> sq->size)
		return (INF);
	return (t);
}

t_vec	square_normal(t_square *sq, t_coord o, t_coord p)
{
	if (vec_dot(sq->n, vec_init(o, p)) >= 0)
		return (vec_scale(sq->n, -1));
	return (sq->n);
}
