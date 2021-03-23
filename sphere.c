/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:22:28 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 22:24:27 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sphere_init(t_figure *fig, char *line)
{
	t_sphere	*sp;
	char		*s;

	sp = (t_sphere*)malloc(sizeof(t_sphere));
	if (sp == 0)
		minirt_exit(line);
	fig->param = (void*)sp;
	s = line;
	s += 2;
	if (read_coord(&s, &(sp->pos)) == 0)
		minirt_exit(line);
	while (*s == '\t' || *s == ' ')
		s++;
	if (!ft_isdigit(*s) && *s != '.')
		minirt_exit(line);
	sp->radius = ft_atof(s);
	while (ft_isdigit(*s) || *s == '.')
		s++;
	if (sp->radius < 0 || read_color(&s, &(fig->color)) == 0)
		minirt_exit(line);
	while (*s == '\t' || *s == ' ')
		if (*(++s) == '\0')
			break ;
	if (*s != '\0')
		minirt_exit(line);
}
