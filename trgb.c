/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:24:45 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 19:50:17 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trgb_init(int t, int r, int g, int b)
{
	if (t > 0xff)
		t = 0xff;
	if (r > 0xff)
		r = 0xff;
	if (g > 0xff)
		g = 0xff;
	if (b > 0xff)
		b = 0xff;
	return (t << 24 | r << 16 | g << 8 | b);
}

int		trgb_get_t(int trgb)
{
	return ((trgb & 0xFF000000) >> 24);
}

int		trgb_get_r(int trgb)
{
	return ((trgb & 0xFF0000) >> 16);
}

int		trgb_get_g(int trgb)
{
	return ((trgb & 0xFF00) >> 8);
}

int		trgb_get_b(int trgb)
{
	return (trgb & 0xFF);
}
