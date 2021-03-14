/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:37:27 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/14 21:33:08 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*sphere_init(t_coord center, double diameter, int color)
{
	t_sphere	*sp;

	sp = (t_sphere*)malloc(sizeof(t_sphere));
	if (sp)
	{
		sp->p = center;
		sp->r = diameter / 2;
		cp->color = color;
	}
	return (sp);
}
