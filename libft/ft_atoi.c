/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:15:14 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/07 19:10:33 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	size_t	i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		sign -= s[i++] % '+';
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i++] - '0');
		if (num < 0)
			break ;
	}
	if (num < 0)
		return (sign > 0 ? -1 : 0);
	return ((int)(num * sign));
}
