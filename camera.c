/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:33:10 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/19 20:32:32 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_init(char *line)
{
	t_canvas	*cnv;
	t_camera	*cam;
	t_vec		ang;
	char		*s;

	cnv = (t_canvas *)malloc(sizeof(t_canvas));
	if (cnv == 0)
		minirt_exit(line);
	cam = &(cnv->cam);
	s = line + 1;
	if (read_coord(&s, &cam->pos) == 0
		|| read_vec(&s, &ang) == 0
		|| read_double(&s, &cam->fov) == 0
		|| cam->fov < 60 || cam->fov > 180) //TODO fov in [90; 180];
		minirt_exit(line);
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s != '\0')
		minirt_exit(line);
	cam->rot = rot_init(ang);
	ft_lstadd_back(&g_data.cnvs, ft_lstnew(cnv));
}

void	image_init(void)
{
	t_img		*img;
	t_win		*win;
	t_list		*elem;

	win = &g_data.win;
	elem = g_data.cnvs;
	while (elem)
	{
		img = &((t_canvas *)elem->content)->img;
		img->ptr = mlx_new_image(g_data.mlx, win->w, win->h);
		img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->lnlen, &img->endian);
		elem = elem->next;
	}
}

void	pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.lnlen + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
