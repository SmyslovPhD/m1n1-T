/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:14:27 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/06 23:10:33 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char*)haystack);
	i = ft_strchr(haystack, needle[0]) - haystack;
	while (i + n_len <= len)
	{
		if (ft_strncmp(&haystack[i++], needle, n_len) == 0)
			return (&((char*)haystack)[i - 1]);
		i = ft_strchr(&((char*)haystack)[i], needle[0]) - haystack;
	}
	return (0);
}
