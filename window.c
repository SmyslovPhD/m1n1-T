/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/27 23:44:41 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_init(char *line)
{
	t_win		*win;
	char		*tmp;

	win = &g_data.win;
	if (win->ptr)
		minirt_exit(line);
	tmp = line + 1;
	tmp++;
	win->w = ft_atoi(tmp);
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	win->h = ft_atoi(tmp);
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (win->w < 1 || win->h < 1)
		minirt_exit(line);
}
