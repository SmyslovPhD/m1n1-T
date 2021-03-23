/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:24:48 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 22:32:21 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			read_coord(char **line, t_coord *dot)
{
	char		*s;
	s = *line;
	while (*s == ' ' || *s == '\t')
		s++;
	if (!ft_isdigit(*s) && !ft_strchr("-.", *s))
		return (0);
	dot->x = ft_atof(s);
	while (ft_isdigit(*s) || ft_strchr("-.", *s))
		s++;
	if (*s != ',')
		return (0);
	dot->y = ft_atof(++s);
	while (ft_isdigit(*s) || ft_strchr("-.", *s))
		s++;
	if (*s != ',')
		return (0);
	dot->z = ft_atof(++s);
	while (ft_isdigit(*s) || ft_strchr("-.", *s))
		s++;
	*line = s;
	return (1);
}

int			read_vector(char **line, t_vector *v)
{
	double		len;

	if (read_coord(line, v) == 0)
		return (0);
	len = vector_len(*v);
	if (len > 1.004 || len < .995)
		ft_printf("Error: vector sells, but who's buying?\n");
	*v = vector_normalize(*v);
	return (1);
}

int			read_color(char **line, int *color)
{
	int		chanel[3];
	int		i;
	char	*s;

	s = *line;
	while (*s == '\t' || *s == ' ')
		s++;
	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(*s))
			return (0);
		chanel[i] = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
		if (chanel[i] > 255)
			return (0);
		if (i < 2 && *s == ',')
			s++;
		i++;
	}
	*line = s;
	*color = trgb_init(0, chanel[0], chanel[1], chanel[2]);
	return (1);
}
