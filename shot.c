/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:52:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/28 19:44:56 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*shot_name(int k)
{
	char	*a;
	char	*b;

	a = ft_itoa(k);
	b = ft_strjoin("screenshots/camera_", a);
	free(a);
	a = ft_strjoin(b, ".bmp");
	free(b);
	return (a);
}

static void	shot_header(int fd, t_img img)
{
	char	head[54];
	int		size;

	ft_bzero(head, 54);
	ft_strlcpy(head, "BM", 3);
	size = 54 + img.bpp / 8 * g_data.win.w * g_data.win.h;
	*(int *)(head + 2) = size;
	head[10] = 54;
	head[14] = 40;
	*(int *)(head + 18) = g_data.win.w;
	*(int *)(head + 22) = g_data.win.h;
	head[26] = 1;
	*(short *)(head + 28) = (short)(img.bpp);
	write(fd, head, sizeof(head));
}

static void	shot_body(int fd, t_img img)
{
	int	i;
	int	j;

	i = g_data.win.h;
	while (i--)
	{
		j = 0;
		while (j < g_data.win.w)
		{
			write(fd, (int *)(img.addr + (i * img.lnlen + j * img.bpp / 8)),
				sizeof(int));
			j++;
		}
	}
}

void	screenshot(t_canvas *cnv)
{
	static int	k = 0;
	int			fd;
	char		*s;

	s = shot_name(k);
	fd = open(s, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
		minirt_exit(ft_strdup("Can't create screenshot!"));
	shot_header(fd, cnv->img);
	shot_body(fd, cnv->img);
	close(fd);
	printf("camera %d saved in %s file\n", k++, s);
	free(s);
}
