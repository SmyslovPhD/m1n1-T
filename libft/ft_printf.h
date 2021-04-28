/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:10:07 by kbraum            #+#    #+#             */
/*   Updated: 2021/01/21 20:19:43 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_N 1
# define FLAG_M 2
# define FLAG_D 4

# include <stdarg.h>
# include "libft.h"

typedef struct	s_ftprntf_data
{
	int			width;
	int			prec;
	int			len;
	char		flag;
}				t_ftprintf_data;

int				ft_printf(const char *format, ...);

#endif
