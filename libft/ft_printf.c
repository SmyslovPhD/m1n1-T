/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:40:01 by kbraum            #+#    #+#             */
/*   Updated: 2021/01/25 17:08:47 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_printf_conv_param(const char *f, va_list ap,
		t_ftprintf_data *p)
{
	p->flag = 0;
	while (*f == '0' || *f == '-')
	{
		p->flag |= (*f == '-') * FLAG_M;
		p->flag |= (*f++ == '0') * FLAG_N;
	}
	p->width = *f == '*' ? va_arg(ap, int) : ft_atoi(f);
	p->flag = (*f == '*' && p->width < 0) ? p->flag | FLAG_M : p->flag;
	p->flag = p->flag & FLAG_M ? p->flag & ~FLAG_N : p->flag;
	p->width = ft_abs(p->width);
	while (ft_isdigit(*f) || *f == '*')
		f++;
	p->flag |= (*f == '.') * FLAG_D;
	f += *f == '.';
	p->prec = -1;
	if (p->flag & FLAG_D)
		p->prec = *f == '*' ? va_arg(ap, int) : ft_atoi(f);
	if (p->flag & FLAG_D && *f == '*' && p->prec < 0)
		p->flag &= ~FLAG_D;
	while (ft_isdigit(*f) || *f == '*')
		f++;
	if ((ft_strchr("diouxX", *f) && p->flag & FLAG_D) || ft_strchr("spc", *f))
		p->flag &= ~FLAG_N;
	p->prec = (p->flag & FLAG_N) ? p->width : p->prec;
	return (f);
}

static char			*ft_printf_conv_str(char c, va_list ap)
{
	char	*s;
	char	*tmp;

	s = 0;
	if (c == 'c' || c == '%')
		s = ft_ctos(c == 'c' ? va_arg(ap, int) : '%');
	if (c == 's')
		s = ft_strdup(va_arg(ap, char*));
	if (c == 'p')
	{
		tmp = ft_lutof((unsigned long)va_arg(ap, void*), 'x');
		s = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(ap, int));
	if (ft_strchr("ouxX", c))
		s = ft_lutof(va_arg(ap, unsigned int), c);
	if (c == 's' && s == 0)
		s = ft_strdup("(null)");
	return (s);
}

static char			*ft_printf_conv_prec(const char c, t_ftprintf_data *p,
		char *s)
{
	char	*tmp;

	if (p->prec < 0 || c == 'c')
		return (s);
	if (c == 's' && p->prec < p->len)
		p->len = p->prec;
	else if (*s == '0' && p->prec == 0 && p->flag & FLAG_D && c != '%')
		p->len = c == 'p' ? 2 : ft_strlcpy(s, " ", 2) - 1;
	else if (ft_strchr("diouxX%", c) && (p->flag & FLAG_D || p->flag & FLAG_N))
	{
		p->prec += *s == '-' && p->flag & FLAG_D;
		while (p->len < p->prec)
		{
			tmp = s;
			s = ft_strjoin("0", s);
			free(tmp);
			p->len++;
		}
		if ((tmp = ft_strchr(s, '-')))
			ft_cswap(s, tmp);
	}
	return (s);
}

static int			ft_printf_conv(const char *f, va_list ap)
{
	t_ftprintf_data	p;
	int				n;
	char			*s;

	n = 0;
	f = ft_printf_conv_param(f, ap, &p);
	s = ft_printf_conv_str(*f, ap);
	p.len = *f == 'c' ? 1 : ft_strlen(s);
	s = ft_printf_conv_prec(*f, &p, s);
	if (s == 0)
		return (-1);
	while ((p.flag & FLAG_M) == 0 && p.width-- > p.len)
		n += write(1, " ", 1);
	n += write(1, s, p.len);
	while (p.flag & FLAG_M && p.width-- > p.len)
		n += write(1, " ", 1);
	free(s);
	return (n);
}

int					ft_printf(const char *f, ...)
{
	va_list	ap;
	int		n;
	int		m;

	va_start(ap, f);
	n = 0;
	while (*f)
	{
		m = 0;
		if (*f == '%' && f[1] != '\0')
		{
			m += ft_printf_conv(++f, ap);
			while (ft_isdigit(*f) || ft_strchr(".*-", *f))
				f++;
		}
		else
			m += write(1, f, 1);
		if (m < 0)
			return (-1);
		n += m;
		f++;
	}
	va_end(ap);
	return (n);
}
