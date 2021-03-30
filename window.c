/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/30 20:47:34 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_init(char *line)
{
	t_win		*win;
	char		*tmp;

	win = &g_data.win;
	tmp = line;
	tmp++;
	win->width = ft_atoi(tmp);
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	win->height = ft_atoi(tmp);
	while (*tmp == ' ' || *tmp == '\t' || ft_isdigit(*tmp))
		tmp++;
	if (win->width < 1 || win->height < 1 || *tmp != '\0' || win->ptr)
		minirt_exit(line);
	win->ptr = mlx_new_window(g_data.mlx, win->width, win->height, "miniRT");
}
