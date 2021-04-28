/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:05:12 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/09 19:14:44 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*m;

	if (s == 0 || f == 0)
		return (0);
	i = 0;
	m = (char*)malloc(ft_strlen(s) + 1);
	if (m == 0)
		return (0);
	ft_strlcpy(m, s, ft_strlen(s) + 1);
	while (m[i])
	{
		m[i] = f(i, m[i]);
		i++;
	}
	return (m);
}
