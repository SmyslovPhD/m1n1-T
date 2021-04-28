/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:31:00 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/20 23:32:51 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i])
		if ((unsigned char)s[i++] == (unsigned char)c)
			return ((char *)s + i - 1);
	return (0);
}
