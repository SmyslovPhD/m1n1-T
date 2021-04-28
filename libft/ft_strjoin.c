/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:51:31 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/09 17:25:32 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	len;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = (char*)malloc(len);
	if (j)
	{
		ft_strlcpy(j, s1, ft_strlen(s1) + 1);
		ft_strlcat(&(j[ft_strlen(s1)]), s2, len);
	}
	return (j);
}
