/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:20:39 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/20 21:41:11 by kbraum           ###   ########.fr       */
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
	else
		minirt_exit(line);
	ft_lstadd_back(&g_data.figures, ft_lstnew((void*)fig));
}

double		figure_getdist(t_figure *fig, t_coord o, t_coord d)
{
	if (fig->id == ID_SP)
		return (sphere_getdist(fig->param, o, d));
	if (fig->id == ID_PL)
		return (plane_getdist(fig->param, o, d));
	return (INF);
}

t_vec	fig_normal(t_figure *fig, t_coord o, t_coord p)
{
	if (fig->id == ID_SP)
		return (sphere_normal(fig->param, o, p));
	if (fig->id == ID_PL)
		return (plane_normal(fig->param, o, p));
	return ((t_vec){0, 0, 0});
}

t_figure	*fig_closest(t_coord o, t_coord d, double *start, double end)
{
	t_list		*elem;
	double		reserve_start;
	double		dist;
	t_figure	*fig;

	fig = 0;
	if (start == 0)
	{
		start = &reserve_start;
		reserve_start = T_MIN;
	}
	elem = g_data.figures;
	while (elem)
	{
		dist = figure_getdist(elem->content, o, d);
		if (dist > *start && dist < end - T_MIN)
		{
			end = dist;
			fig = elem->content;
		}
		elem = elem->next;
	}
	*start = end;
	return (fig);
}
