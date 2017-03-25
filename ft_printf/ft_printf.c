/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:46:40 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/24 17:26:37 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str			g_res;

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fmt		fmt;
	int			res;

	va_start(ap, format);
	str_init(&g_res);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = parse(&fmt, ++format, ap);
			format_fmt(&fmt, ap);
		}
		else
			APPEND_CHAR(*(format++));
	}
	va_end(ap);
	write(1, g_res.string, g_res.length);
	res = g_res.length;
	str_free(&g_res);
	return (res);
}

int				ft_fdprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_fmt		fmt;
	int			res;

	va_start(ap, format);
	str_init(&g_res);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = parse(&fmt, ++format, ap);
			format_fmt(&fmt, ap);
		}
		else
			APPEND_CHAR(*(format++));
	}
	va_end(ap);
	write(fd, g_res.string, g_res.length);
	res = g_res.length;
	str_free(&g_res);
	return (res);
}

int				ft_sprintf(char *dest, const char *format, ...)
{
	va_list		ap;
	t_fmt		fmt;
	int			res;

	va_start(ap, format);
	str_init(&g_res);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = parse(&fmt, ++format, ap);
			format_fmt(&fmt, ap);
		}
		else
			APPEND_CHAR(*(format++));
	}
	va_end(ap);
	g_res.string[g_res.length] = '\0';
	STRCPY(dest, g_res.string);
	res = g_res.length;
	str_free(&g_res);
	return (g_res.length);
}

int				ft_asprintf(char **dest, const char *format, ...)
{
	va_list		ap;
	t_fmt		fmt;

	va_start(ap, format);
	str_init(&g_res);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = parse(&fmt, ++format, ap);
			format_fmt(&fmt, ap);
		}
		else
			APPEND_CHAR(*(format++));
	}
	va_end(ap);
	g_res.string[g_res.length] = '\0';
	*dest = g_res.string;
	return (g_res.length);
}
