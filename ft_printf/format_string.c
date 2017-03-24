/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:22:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 19:58:21 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_string_normal(t_fmt *fmt, char *string)
{
	int			len;

	len = STRLEN(string);
	if (fmt->has_precision && fmt->precision < len)
		len = fmt->precision;
	if (fmt->has_width && fmt->width > len && !fmt->f_minus)
		APPEND_CHAR_N(fmt->f_zero ? '0' : ' ', fmt->width - len);
	APPEND_STRING_N(string, len);
	if (fmt->has_width && fmt->width > len && fmt->f_minus)
		APPEND_CHAR_N(' ', fmt->width - len);

}

char			*wstring_to_string(const wchar_t *wstring, int len)
{
	char		*string;
	int			i;

	string = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		string[i] = wstring[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

void			format_wstring(t_fmt *fmt, va_list ap)
{
	wchar_t		*wstring;
	char		*string;
	int			len;

	wstring = va_arg(ap, wchar_t *);
	wstring = wstring ?: L"(null)";
	len = 0;
	while (wstring[len] != '\0')
		len++;
	string = wstring_to_string(wstring, len);
	format_string_normal(fmt, string);
	free(string);
}

void			format_string(t_fmt *fmt, va_list ap)
{
	char		*string;

	string = va_arg(ap, char *);
	string = string ?: "(null)";
	format_string_normal(fmt, string);
}
