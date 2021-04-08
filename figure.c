/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:20:39 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/08 23:18:19 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	figure_init(char *line)
{
	t_figure	*fig;

	fig = (t_figure*)malloc(sizeof(t_figure));
	if (fig == 0)
		minirt_exit(line);
	if (line[0] == 's' && line[1] == 'p')
		sphere_init(fig, line);
	else
		minirt_exit(line);
	ft_lstadd_back(&g_data.figures, ft_lstnew((void*)fig));
}

double	figure_getdist(t_coord d, t_figure *fig)
{
	double	dist;

	dist = INF;
	if (fig->id == ID_SP)
		dist = sphere_getdist(d, fig->param);
	return (dist);
}
