/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:57:26 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/27 21:37:08 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rot_sincos(const t_vec v, double *s, double *c)
{
	c[0] = sqrt(v.x * v.x + v.z * v.z) / vec_len(v);
	s[0] = v.y / vec_len(v);
	if (v.x == 0 && v.z == 0)
	{
		c[1] = 1;
		s[1] = v.x;
	}
	else
	{
		c[1] = v.z / sqrt(v.x * v.x + v.z * v.z);
		s[1] = v.x / sqrt(v.x * v.x + v.z * v.z);
	}
}

t_rot	rot_init(const t_vec v)
{
	t_rot			rot;
	double			sin_ab[2];
	double			cos_ab[2];

	rot_sincos(v, sin_ab, cos_ab);
	rot.x.x = cos_ab[1];
	rot.x.y = 0;
	rot.x.z = -sin_ab[1];
	rot.y.x = -sin_ab[0] * sin_ab[1];
	rot.y.y = fabs(cos_ab[0]);
	rot.y.z = -sin_ab[0] * cos_ab[1];
	rot.z.x = cos_ab[0] * sin_ab[1];
	rot.z.y = sin_ab[0];
	rot.z.z = cos_ab[0] * cos_ab[1];
	return (rot);
}

t_coord	rotate(const t_rot rot, const t_coord p)
{
	t_coord		r;

	r.x = rot.x.x * p.x + rot.y.x * p.y + rot.z.x * p.z;
	r.y = rot.x.y * p.x + rot.y.y * p.y + rot.z.y * p.z;
	r.z = rot.x.z * p.x + rot.y.z * p.y + rot.z.z * p.z;
	return (r);
}
