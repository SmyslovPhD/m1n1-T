/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_cnv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:29:20 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/11 19:49:36 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_cx(int x, t_win *win)
{
	return (x - win->w / 2);
}

int		get_cy(int y, t_win *win)
{
	return (win->h / 2 - y);
}

int		get_mx(int x, t_win *win)
{
	return (win->w / 2 + x);
}

int		get_my(int y, t_win *win)
{
	return (win->h / 2 + y);
}


