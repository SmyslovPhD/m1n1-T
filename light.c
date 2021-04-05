/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:33:41 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/05 21:14:57 by kbraum           ###   ########.fr       */
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
