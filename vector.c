/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:50:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/13 21:15:25 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_init(t_coord a, t_coord b)
{
	t_vector	v;

	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	return (v);
}

t_vector	vector_normalize(t_vector v)
{
	t_vector	vn;
	double		len;

	len = vector_len(v);
	vn.x = v.x / len;
	vn.y = v.y / len;
	vn.z = v.z / len;
	return (vn);
}

t_vector	vector_sum(t_vector a, t_vector b)
{
	t_vector	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	
	return (c);
}

t_vector	vector_scale(t_coord d, double c)
{
	t_vector	cd;

	cd.x = d.x * c;
	cd.y = d.y * c;
	cd.z = d.z * c;
	return (cd);
}

double		vector_len(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		dot_product(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
