/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:22:28 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/31 20:05:44 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sphere_init(t_figure *fig, char *line)
{
	t_sphere	*sp;
	char		*s;

	fig->id = ID_SP;
	sp = (t_sphere*)malloc(sizeof(t_sphere));
	if (sp == 0)
		minirt_exit(line);
	fig->param = (void*)sp;
	s = line + 2;
	if (read_coord(&s, &(sp->pos)) == 0
		|| read_double(&s, &(sp->radius)) == 0
		|| sp->radius < 0
		|| read_color(&s, &(fig->color)) == 0)
		minirt_exit(line);
}
