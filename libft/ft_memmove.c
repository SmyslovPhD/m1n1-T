/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:03 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/04 22:34:04 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst || src || !len)
	{
		if (dst < src)
			while (i < len)
			{
				((char*)dst)[i] = ((char*)src)[i];
				i++;
			}
		else
			while (len--)
				((char*)dst)[len] = ((char*)src)[len];
	}
	return (dst);
}
