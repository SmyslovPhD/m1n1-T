/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:23:35 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/11 21:21:59 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H
# define WIN_SIZE 512, 512

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			lnlen;
	int			endian;
}				t_img;

typedef struct	s_win
{
	void		*ptr;
	int			w;
	int			h;
}				t_win;

typedef struct	s_data
{
	void		*mlx;
	t_win		win;
	t_img		img;
}				t_data;

int				get_cx(int x, t_win *win);
int				get_cy(int y, t_win *win);
int				get_mx(int x, t_win *win);
int				get_my(int y, t_win *win);

#endif
