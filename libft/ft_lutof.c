/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:19:31 by kbraum            #+#    #+#             */
/*   Updated: 2021/01/25 16:20:03 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_ltof_base(char c)
{
	if (c == 'X' || c == 'x')
		return (16);
	if (c == 'o')
		return (8);
	return (10);
}

char					*ft_lutof(unsigned long nbr, char c)
{
	char			*s;
	char			*fmt;
	unsigned long	base;
	size_t			i;

	fmt = (c == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	base = ft_ltof_base(c);
	i = 0;
	while (nbr / ft_powlu(base, i) >= base)
		i++;
	s = (char*)malloc((++i + 1) * sizeof(char));
	s[i] = '\0';
	if (nbr == 0)
		s[--i] = fmt[0];
	while (i)
	{
		s[--i] = fmt[nbr % base];
		nbr /= base;
	}
	return (s);
}
