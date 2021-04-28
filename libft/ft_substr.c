/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:05:15 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/09 17:40:54 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == 0)
		return (0);
	p = 0;
	len = start >= ft_strlen(s) ? 0 : len;
	p = (char*)malloc(len + 1);
	if (p)
		ft_strlcpy(p, &(s[start]), len + 1);
	return (p);
}
