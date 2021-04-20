/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/20 21:18:22 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	g_data;

void	minirt_exit(char *line)
{
	int		exit_code;

	if (line)
	{
		exit_code = 1;
		printf("Error\n\"%s\"\n", line);
		free(line);
	}
	else
		exit_code = 0;
	exit(exit_code);
}

int		key_hook(int keycode, t_list **cnv)	//j
{
	printf("%d\n", keycode);
	if (keycode == 49)
	{
		*cnv = (*cnv)->next;
		if (*cnv == 0)
			*cnv = g_data.cnvs;
		mlx_put_image_to_window(g_data.mlx, g_data.win.ptr,
			((t_canvas *)(*cnv)->content)->img.ptr, 0, 0);
	} else if (keycode == 53)
		minirt_exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*cnv;

	if (argc != 2)
		return (printf("no args\n"));
	data_init(argv[1]);
	ft_lstiter(g_data.cnvs, (void (*)(void *))image_render);
	if (g_data.cnvs == 0)
		minirt_exit(ft_strdup("NO CAMS"));
	cnv = g_data.cnvs;
	mlx_put_image_to_window(g_data.mlx, g_data.win.ptr,
		((t_canvas *)cnv->content)->img.ptr, 0, 0);
	mlx_key_hook(g_data.win.ptr, key_hook, &cnv);	//k
	mlx_loop(g_data.mlx);
}
