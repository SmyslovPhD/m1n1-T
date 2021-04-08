/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:33:41 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/06 18:56:53 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ambient_init(char *line)
{
	t_amb	*amb;
	char	*s;

	amb = &g_data.amb;
	s = line + 1;
	if (read_double(&s, &amb->ratio) == 0
		|| read_color(&s, &amb->color) == 0
		|| amb->ratio < 0 || amb->ratio > 1)
		minirt_exit(line);
}

void	light_init(char *line)
{
	t_light	*li;
	char	*s;

	li = (t_light *)malloc(sizeof(t_light));
	if (li == 0)
		minirt_exit(line);
	s = line + 1;
	if (read_coord(&s, &li->pos) == 0
		|| read_double(&s, &li->ratio) == 0
		|| li->ratio < 0 || li->ratio > 1
		|| read_color(&s, &li->color) == 0)
		minirt_exit(line);
	ft_lstadd_back(&g_data.lights, ft_lstnew((void *)li));
}
