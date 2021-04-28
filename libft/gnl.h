/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:15:20 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/30 21:28:05 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H

# define GNL_H
# define BUFFER_SIZE 1024
# include "libft.h"

typedef struct			s_list_buf
{
	int					fd;
	char				buf[BUFFER_SIZE + 1];
	struct s_list_buf	*next;
}						t_list_buf;

#endif
