/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:50:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/23 21:58:32 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_init(t_coord a, t_coord b)
{
	t_vec	v;

	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	return (v);
}

t_vec	vec_norm(t_vec v)
{
	t_vec		vn;
	double		len;

	len = vec_len(v);
	vn.x = v.x / len;
	vn.y = v.y / len;
	vn.z = v.z / len;
	return (vn);
}

t_vec	vec_sum(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec	vec_scale(t_vec d, double c)
{
	t_vec	cd;

	cd.x = d.x * c;
	cd.y = d.y * c;
	cd.z = d.z * c;
	return (cd);
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec	c;
	
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

double	vec_len(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
