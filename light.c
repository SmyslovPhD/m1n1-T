/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:33:41 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/19 22:51:41 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ambient_init(char *line)
{
	t_amb	*amb;
	char	*s;

	amb = &g_data.amb;
	s = line + 1;
	if (read_double(&s, &amb->ratio) == 0
		|| read_color(&s, &amb->color) == 0
		|| amb->ratio < 0 || amb->ratio > 1)
		minirt_exit(line);
}

void	light_init(char *line)
{
	t_light	*li;
	char	*s;

	li = (t_light *)malloc(sizeof(t_light));
	if (li == 0)
		minirt_exit(line);
	s = line + 1;
	if (read_coord(&s, &li->pos) == 0
		|| read_double(&s, &li->ratio) == 0
		|| li->ratio < 0 || li->ratio > 1
		|| read_color(&s, &li->color) == 0)
		minirt_exit(line);
	ft_lstadd_back(&g_data.lights, ft_lstnew((void *)li));
}

static
void	intence_sum(double *intence, double ratio, int color)
{
	int			i;
	static int	(*f[3])(int) = {trgb_get_r, trgb_get_g, trgb_get_b};

	i = 3;
	while (i--)
		intence[i] += ratio * (f[i])(color) / 255;
}

int	li_intersec(t_figure *fig, t_coord o, t_coord p)
{
	double		intence[3];
	t_list		*elem;
	t_light		*li;
	t_vec		n;
	t_vec		l;

	intence[0] = 0;
	intence[1] = 0;
	intence[2] = 0;
	intence_sum(intence, g_data.amb.ratio, g_data.amb.color);
	n = fig_norm(fig, o, p);
	elem = g_data.lights;
	while (elem)
	{
		li = elem->content;
		l = vec_init(p, li->pos);
		if (vec_dot(n, l) > 0
			&& fig_closest(p, vec_sum(p, vec_norm(l)), 0, vec_len(l)) == 0)
			intence_sum(intence, 
				li->ratio * pow(vec_dot(n, l) / vec_len(l) / vec_len(n), 2),
				li->color);
		elem = elem->next;
	}
	return (color_shade(fig->color, intence));
}
