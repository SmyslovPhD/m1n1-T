/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/28 19:51:15 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_init(char *line)
{
	t_win		*win;
	char		*tmp;

	win = &g_data.win;
	tmp = line + 1;
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
	if (win->w < 1 || win->h < 1 || win->is_set)
		minirt_exit(line);
	win->is_set = 1;
	if (win->w > mlx_get_screen_width())
		win->w = mlx_get_screen_width();
	if (win->h > mlx_get_screen_height())
		win->h = mlx_get_screen_height();
}
