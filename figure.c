/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:20:39 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/24 21:34:32 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*figure_init(char *line)
{
	t_figure	*fig;

	fig = (t_figure*)malloc(sizeof(t_figure));
	if (fig == 0)
		return (fig);
	if (line[0] == 's' && line[1] == 'p')
		sphere_init(fig, line);
	else
		minirt_exit(line);
	return ((void*)fig);
}
