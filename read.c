/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:40:27 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/28 20:25:51 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	read_double(char **line, double *j)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (!(ft_isdigit(**line) || **line == '.' || **line == '-'))
		return (0);
	*j = ft_atof(*line);
	*line += **line == '-';
	while (ft_isdigit(**line))
		(*line)++;
	*line += **line == '.';
	while (ft_isdigit(**line))
		(*line)++;
	return (1);
}

int	read_coord(char **line, t_coord *dot)
{
	if (read_double(line, &dot->x) == 0)
		return (0);
	*line += **line == ',';
	if (read_double(line, &dot->y) == 0)
		return (0);
	*line += **line == ',';
	if (read_double(line, &dot->z) == 0)
		return (0);
	return (1);
}

int	read_vec(char **line, t_vec *v)
{
	double		len;

	if (read_coord(line, v) == 0)
		return (0);
	len = vec_len(*v);
	if (len == 0)
		return (0);
	if (len > 1.004 || len < .995)
		printf("Error\n vector sells, but who's buying?\n");
	*v = vec_norm(*v);
	return (1);
}

int	read_color(char **line, int *color)
{
	int		chanel[3];
	int		i;

	while (**line == '\t' || **line == ' ')
		(*line)++;
	i = 0;
	while (i < 3)
	{
		chanel[i] = ft_atoi(*line);
		while (ft_isdigit(**line))
			(*line)++;
		if (i++ < 3 && **line == ',')
			(*line)++;
	}
	while (**line == '\t' || **line == ' ')
		(*line)++;
	if (**line != '\0')
		return (0);
	*color = trgb_init(0, chanel[0], chanel[1], chanel[2]);
	return (1);
}
