/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:20:39 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/25 17:29:50 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		figure_init(char *line)
{
	t_figure	*fig;

	fig = (t_figure*)malloc(sizeof(t_figure));
	if (fig == 0)
		minirt_exit(line);
	if (line[0] == 'p' && line[1] == 'l')
		plane_init(fig, line);
	else if (line[0] == 's' && line[1] == 'p')
		sphere_init(fig, line);
	else if (line[0] == 's' && line[1] == 'q')
		square_init(fig, line);
	else if (line[0] == 't' && line[1] == 'r')
		triangle_init(fig, line);
	else
		minirt_exit(line);
	ft_lstadd_back(&g_data.figures, ft_lstnew(fig));
}

double		figure_getdist(t_figure *fig, t_coord o, t_vec od, double min)
{
	if (fig->id == ID_SP)
		return (sphere_getdist(fig->param, o, od, min));
	if (fig->id == ID_PL)
		return (plane_getdist(fig->param, o, od));
	if (fig->id == ID_TR)
		return (triangle_getdist(fig->param, o, od));
	return (INF);
}

t_vec	fig_normal(t_figure *fig, t_coord o, t_coord p)
{
	if (fig->id == ID_SP)
		return (sphere_normal(fig->param, o, p));
	if (fig->id == ID_PL)
		return (plane_normal(fig->param, o, p));
	if (fig->id == ID_TR)
		return (triangle_normal(fig->param, o, p));
	return ((t_vec){0, 0, 0});
}

t_figure	*fig_closest(t_coord o, t_vec od, double *start, double end)
{
	t_list		*elem;
	t_figure	*fig;
	double		dist;
	double		reserve_start;

	reserve_start = T_MIN;
	if (start == 0)
		start = &reserve_start;
	fig = 0;
	elem = g_data.figures;
	while (elem)
	{
		dist = figure_getdist(elem->content, o, od, *start);
		if (dist > *start && dist < end - T_MIN)
		{
			end = dist;
			fig = elem->content;
		}
		if (start == &reserve_start && fig)
			break;
		elem = elem->next;
	}
	*start = end;
	return (fig);
}
