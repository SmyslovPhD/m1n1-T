/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:24:48 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 19:44:21 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord		read_coord(char **line)
{
	t_coord		dot;
	char		*s;

	s = *line;
	while (*s == ' ' || *s == '\t')
		s++;
	if (!ft_isdigit(*s) && !ft_strchr("-.", *s))
		minirt_exit(*line);
	dot.x = ft_atof(s);
	while (ft_isdigit(*s) || ft_strchr("-.", *s))
		s++;
	if (*s != ',')
		minirt_exit(*line);
	dot.y = ft_atof(++s);
	while (ft_isdigit(*s) || ft_strchr("-.", *s))
		s++;
	if (*s != ',')
		minirt_exit(*line);
	dot.z = ft_atof(++s);
	while (ft_isdigit(*s) || ft_strchr("-.", *s))
		s++;
	*line = s;
	return (dot);
}

int			read_color(char **line)
{
	int		chanel[3];
	char	*s;

	s = *line;
	if (!ft_isdigit(*s))
		minirt_exit(*line);
	chanel[0] = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if (*s != ',')
		minirt_exit(*line);
	chanel[1] = ft_atoi(++s);
	while (ft_isdigit(*s))
		s++;
	if (*s != ',')
		minirt_exit(*line);
	chanel[2] = ft_atoi(++s);
	while (ft_isdigit(*s))
		s++;
	if (chanel[0] < 0 || chanel[0] > 255 ||
		chanel[1] < 0 || chanel[1] > 255 ||
		chanel[2] < 0 || chanel[2] > 255)
		minirt_exit(*line);
	*line = s;
	return (trgb_init(0, chanel[0], chanel[1], chanel[2]));
}

t_vector	read_vector(char **line)
{
	t_vector	v;
	double		len;

	v = (t_vector)read_coord(line);
	len = vector_len(v);
	if (len > 1.004 || len < .995)
		ft_printf("Error: vector sells, but who's buying?\n");
	v = vector_normalize(v);
	return (v);
}
