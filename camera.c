/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:33:10 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/31 20:04:16 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_init(char *line)
{
	t_canvas	*cnv;
	t_camera	*cam;
	char		*s;

	cnv = (t_canvas *)malloc(sizeof(t_canvas));
	if (cnv == 0)
		minirt_exit(line);
	cam = &(cnv->cam);
	s = line + 1;
	if (read_coord(&s, &(cam->pos)) == 0
		|| read_vector(&s, &(cam->ang)) == 0)
		minirt_exit(line);
	cam->fov = ft_atoi(s);
	while (ft_isdigit(*s) || *s == ' ' || *s == '\t')
		s++;
	if (*s != '\0' || cam->fov < 90 || cam->fov > 180)
		minirt_exit(line);
	ft_lstadd_back(&g_data.cnvs, ft_lstnew((void *)cnv));
}

void	image_init(t_list *cnvs)
{
	t_img		*img;
	t_win		*win;

	win = &g_data.win;
	while (cnvs)
	{
		img = &((t_canvas *)cnvs->content)->img;
		img->ptr = mlx_new_image(g_data.mlx, win->width, win->height);
		img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->lnlen, &img->endian);
		cnvs = cnvs->next;
	}
}
