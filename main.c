/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:19:23 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/10 23:18:35 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_win	win_init(void* mlx, int width, int height)
{
	t_win	win;
	
	win.pnt = mlx_new_window(mlx, width, height, "miniRT");
	win.w = width;
	win.h = height;
	return (win);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->lnlen + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int		wintocan_x(int x,	t_win *win)
{
	w
}

int		canvas_get_x(int x, t_win *win)
{
	return (x - win->w/2);
}

int		canvas_get_y(int y, t_win *win)
{
	return (win->h/2 - y);
}

int		mouse_hook(int button, int x, int y, t_win *param)
{
	(void)param;
	(void)button;
	printf("monitor:\t%d, %d\n canvas:\t%d, %d\n\n",
			x, y, canvas_get_x(x, param), canvas_get_y(y, param));
	return (666);
}

int		main(void)
{
	void	*mlx;
	t_win	win;
	t_img	img;

	mlx = mlx_init();
	win = win_init(mlx, WIN_SIZE);
	img.img = mlx_new_image(mlx, WIN_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.lnlen, &img.endian);
	mlx_put_image_to_window(mlx, win.pnt, img.img, 0, 0);
	mlx_mouse_hook(win.pnt, mouse_hook, &win);
	mlx_loop(mlx);
	return (0);
}
