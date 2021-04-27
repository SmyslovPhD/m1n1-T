/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:14:18 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/27 21:27:12 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static
	void	square_convert(t_square sq, t_figure *fig)
{
	t_figure	*fig_new;
	t_triangle	*tr[2];
	double		a;

	fig_new = (t_figure *)malloc(sizeof(t_figure));
	tr[0] = (t_triangle *)malloc(sizeof(t_triangle));
	tr[1] = (t_triangle *)malloc(sizeof(t_triangle));
	if (fig_new == 0 || tr[0] == 0 || tr[1] == 0)
		minirt_exit(ft_strdup("malloc err"));
	a = sq.size / 2;
	fig->param = tr[0];
	tr[0]->p1 = vec_sum(sq.pos, rotate(sq.rot, (t_vec){-a, -a, 0}));
	tr[0]->p0 = vec_sum(sq.pos, rotate(sq.rot, (t_vec){a, a, 0}));
	tr[0]->p2 = vec_sum(sq.pos, rotate(sq.rot, (t_vec){a, -a, 0}));
	tr[0]->n = vec_cross(vec_init(tr[0]->p0, tr[0]->p1),
			vec_init(tr[0]->p0, tr[0]->p2));
	tr[1]->p0 = tr[0]->p0;
	tr[1]->p1 = tr[0]->p1;
	tr[1]->p2 = vec_sum(sq.pos, rotate(sq.rot, (t_vec){-a, a, 0}));
	tr[1]->n = vec_scale(tr[0]->n, -1);
	fig_new->id = fig->id;
	fig_new->param = (tr[1]);
	fig_new->color = fig->color;
	ft_lstadd_back(&g_data.figures, ft_lstnew(fig_new));
}

void	square_init(t_figure *fig, char *line)
{
	t_square	sq;
	char		*s;

	s = line + 2;
	fig->id = ID_TR;
	if (read_coord(&s, &sq.pos) == 0
		|| read_vec(&s, &sq.n) == 0
		|| read_double(&s, &sq.size) == 0
		|| read_color(&s, &fig->color) == 0)
		minirt_exit(line);
	sq.rot = rot_init(sq.n);
	square_convert(sq, fig);
}
