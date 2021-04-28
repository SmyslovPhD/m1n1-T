/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:09:46 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/24 18:23:23 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static size_t	ft_split_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		**ft_split_free(char **sp)
{
	size_t	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**sp;

	if (s == 0)
		return (0);
	words = ft_split_count(s, c);
	sp = (char**)malloc((words + 1) * sizeof(char*));
	if (sp == 0)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		sp[i] = (char*)malloc(ft_split_len(s, c) + 1);
		if (sp[i] == 0)
			return (ft_split_free(sp));
		ft_strlcpy(sp[i++], s, ft_split_len(s, c) + 1);
		s += ft_split_len(s, c);
	}
	sp[i] = 0;
	return (sp);
}
