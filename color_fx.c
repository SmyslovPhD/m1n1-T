/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:15:12 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/31 18:27:04 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_add(int c1, int c2)
{
	return (trgb_init(
			trgb_get_t(c1) + trgb_get_t(c2),
			trgb_get_r(c1) + trgb_get_r(c2),
			trgb_get_g(c1) + trgb_get_g(c2),
			trgb_get_b(c1) + trgb_get_b(c2)));
}

int	color_shade(int c, double shade)
{
	return (trgb_init(
			trgb_get_t(c) * shade,
			trgb_get_r(c) * shade,
			trgb_get_g(c) * shade,
			trgb_get_b(c) * shade));
}
