/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:04:44 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/08 20:43:44 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*t;

	if (s1 == 0 || set == 0)
		return (0);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len = ft_strlen(s1);
	if (len)
		while (ft_strchr(set, s1[len - 1]))
			len--;
	t = (char*)malloc(len + 1);
	if (t)
		ft_strlcpy(t, s1, len + 1);
	return (t);
}
