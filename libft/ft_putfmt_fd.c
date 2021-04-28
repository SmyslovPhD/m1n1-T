/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:36:44 by kbraum            #+#    #+#             */
/*   Updated: 2020/12/18 21:11:04 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putfmt_fd(unsigned long nbr, int fd, char c)
{
	unsigned long	m;
	unsigned long	base;
	int				i;
	char			*ftm;

	if (ft_strchr("uxX", c) == 0 || write(fd, 0, 0) == -1)
		return (-1);
	m = 1;
	i = 0;
	ftm = (c == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	base = (c == 'u') ? 10 : 16;
	while (nbr / m > base)
		m *= base;
	while (m != 0)
	{
		i += write(1, &(ftm[nbr / m % base]), 1);
		m /= base;
	}
	return (i);
}
