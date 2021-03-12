/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:02:56 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/12 20:08:54 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h" 

t_win	win_init(void *mlx, char *line)
{
	t_win	win;

	line++;
	win.w = ft_atoi(line);
	while (*line == ' ' || *line == '\t')
		line++;
	while (ft_isdigit(*line))
		line++;
	win.h = ft_atoi(line);
	if (win.w < 1 || win.h < 1)
	{
		free(line);
		exit(1);
	}
	win.ptr = mlx_new_window(mlx, win.w, win.h, "miniRT");
	return (win);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->lnlen + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int		get_sx(int x, t_win *win)
{
	return (win->w / 2 + x);
}

int		get_sy(int y, t_win *win)
{
	return (win->h / 2 + y);
}
