/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/27 22:42:42 by kbraum           ###   ########.fr       */
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
		printf("Error\n%s\n", line);
		free(line);
	}
	else
		exit_code = 0;
	exit(exit_code);
}

int	key_hook(int keycode, t_list **cnv)
{
	if (keycode == 49)
	{
		*cnv = (*cnv)->next;
		if (*cnv == 0)
			*cnv = g_data.cnvs;
		mlx_put_image_to_window(g_data.mlx, g_data.win.ptr,
			((t_canvas *)(*cnv)->content)->img.ptr, 0, 0);
	}
	else if (keycode == 53)
		minirt_exit(0);
	return (0);
}

int	minirt_close(int keycode, void *ptr)
{
	(void)ptr;
	(void)keycode;
	printf("Window close\n");
	minirt_exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*cnv;

	if (argc != 2 && !(argc == 3 && ft_strncmp(argv[2], "--save", 7)))
		return (printf("wrong args\n"));
	g_data.mlx = mlx_init();
	if (g_data.mlx == 0)
		return (printf("mlx error!\n"));
	data_init(argv[1]);
	ft_lstiter(g_data.cnvs, (void (*)(void *))image_render);
	if (argc == 3)
		return (printf("Save in bmp\n"));
	g_data.win.ptr = mlx_new_window(g_data.mlx,
			g_data.win.w, g_data.win.h, "miniRT");
	cnv = g_data.cnvs;
	mlx_put_image_to_window(g_data.mlx, g_data.win.ptr,
		((t_canvas *)cnv->content)->img.ptr, 0, 0);
	mlx_key_hook(g_data.win.ptr, key_hook, &cnv);
	mlx_hook(g_data.win.ptr, 17, 0, minirt_close, 0);
	mlx_loop(g_data.mlx);
}
