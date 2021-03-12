/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:24:45 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/12 21:31:53 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trgb_init(int t, int r, int g, int b)
{
	t = t > 0xff ? 0xff : t;
	r = r > 0xff ? 0xff : r;
	g = g > 0xff ? 0xff : g;
	b = b > 0xff ? 0xff : b;

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
