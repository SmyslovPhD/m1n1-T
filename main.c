/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:05:30 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/23 19:45:27 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_exit(char *line)
{
	if (line)
		free(line);
	ft_printf("Error\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	printf("\n");
	char		*s = ft_strdup("0991,26,1");
	char		*ptr = s;
	
	int			color = read_color(&ptr);
	free(s);
	printf("r: %i\n", trgb_get_r(color));
	printf("g: %i\n", trgb_get_g(color));
	printf("b: %i\n", trgb_get_b(color));
}
