/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:48:10 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/11 20:36:48 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static char	*find_buf(int fd, t_list_buf **list_buf)
{
	t_list_buf	*elem;

	elem = *list_buf;
	while (elem)
	{
		if (fd == elem->fd)
			return (elem->buf);
		elem = elem->next;
	}
	elem = malloc(sizeof(t_list_buf));
	if (elem == 0)
		return (0);
	elem->fd = fd;
	*(elem->buf) = '\0';
	elem->next = *list_buf;
	*list_buf = elem;
	return (elem->buf);
}

static void	clean_buf(int fd, t_list_buf **list_buf)
{
	t_list_buf	*elem;
	t_list_buf	*tmp;

	elem = *list_buf;
	tmp = 0;
	while (elem->fd != fd)
	{
		tmp = elem;
		elem = elem->next;
	}
	if (tmp)
		tmp->next = elem->next;
	else
		*list_buf = elem->next;
	free(elem);
}

static char	*check_next_line(char *buf, char **line)
{
	char	*buf_p;
	char	*line_tmp;

	if (*buf)
	{
		line_tmp = *line;
		if ((buf_p = ft_strchr(buf, '\n')))
		{
			*buf_p = '\0';
			*line = ft_strjoin(*line, buf);
			ft_strlcpy(buf, buf_p + 1, BUFFER_SIZE);
		}
		else
		{
			*line = ft_strjoin(*line, buf);
			*buf = '\0';
		}
		free(line_tmp);
	}
	else
		buf_p = 0;
	return (buf_p);
}

int			get_next_line(int fd, char **line)
{
	static t_list_buf	*list_buf = 0;
	char				*buf;
	char				*buf_p;
	int					n;

	if (BUFFER_SIZE < 0 || line == 0 ||
			(buf = find_buf(fd, &list_buf)) == 0 ||
			(n = read(fd, buf, 0)) < 0)
		return (-1);
	*line = ft_strjoin("", "");
	buf_p = check_next_line(buf, line);
	while (buf_p == 0 && (n = read(fd, buf, BUFFER_SIZE)))
	{
		buf[n] = '\0';
		buf_p = check_next_line(buf, line);
		if (*line == 0)
			return (-1);
	}
	if (buf_p == 0 && n == 0)
	{
		clean_buf(fd, &list_buf);
		return (0);
	}
	return (1);
}
