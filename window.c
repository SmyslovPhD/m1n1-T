/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/05 21:15:39 by kbraum           ###   ########.fr       */
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
	win->width = ft_atoi(tmp);
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	win->height = ft_atoi(tmp);
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (win->width < 1 || win->height < 1)
		minirt_exit(line);
}
