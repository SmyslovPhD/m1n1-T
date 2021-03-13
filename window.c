/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:02:56 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/13 20:30:28 by kbraum           ###   ########.fr       */
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

void	pixel_put(t_img *img, t_dot dot)
{
	char	*dst;

	dst = img->addr + (dot.i * img->lnlen + dot.j * (img->bpp / 8));
	*(unsigned int*)dst = dot.color;
}

t_dot	get_coord_s(t_dot *dot, t_win *win)
{
	t_dot	d;

	d.j = win->w / 2 + dot->j;
	d.i = win->h / 2 + dot->i;
	d.color = dot->color;
	return (d);
}
