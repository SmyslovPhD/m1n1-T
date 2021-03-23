/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:50:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 19:51:01 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_init(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector	vector_normalize(t_coord v)
{
	t_vector	vn;
	double		len;

	len = vector_len(v);
	vn = vector_init(v.x / len, v.y / len, v.z / len);
	return (vn);
}

t_vector	get_vector(t_coord start, t_coord end)
{
	t_vector	v;

	v.x = end.x - start.x;
	v.y = end.y - start.y;
	v.z = end.z - start.z;
	return (v);
}

double		vector_len(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		dot_product(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
