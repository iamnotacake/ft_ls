/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:10:40 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 16:36:30 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		pull_number_unsigned(t_fmt *fmt, va_list ap)
{
	if (fmt->type == 'U' || fmt->type == 'O')
		return ((unsigned long)va_arg(ap, unsigned long));
	if (fmt->type == 'p')
		return ((uintmax_t)va_arg(ap, void *));
	if (STRCMP(fmt->mod, "hh") == 0)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (STRCMP(fmt->mod, "h") == 0)
		return ((unsigned short)va_arg(ap, unsigned int));
	if (STRCMP(fmt->mod, "ll") == 0)
		return ((unsigned long long)va_arg(ap, unsigned long long));
	if (STRCMP(fmt->mod, "l") == 0)
		return ((unsigned long)va_arg(ap, unsigned long));
	if (STRCMP(fmt->mod, "j") == 0)
		return (va_arg(ap, uintmax_t));
	if (STRCMP(fmt->mod, "z") == 0)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

intmax_t		pull_number_signed(t_fmt *fmt, va_list ap)
{
	if (fmt->type == 'D')
		return ((signed long)va_arg(ap, signed long));
	if (STRCMP(fmt->mod, "hh") == 0)
		return ((signed char)va_arg(ap, signed int));
	if (STRCMP(fmt->mod, "h") == 0)
		return ((signed short)va_arg(ap, signed int));
	if (STRCMP(fmt->mod, "ll") == 0)
		return ((signed long long)va_arg(ap, signed long long));
	if (STRCMP(fmt->mod, "l") == 0)
		return ((signed long)va_arg(ap, signed long));
	if (STRCMP(fmt->mod, "j") == 0)
		return (va_arg(ap, intmax_t));
	if (STRCMP(fmt->mod, "z") == 0)
		return (va_arg(ap, size_t));
	return (va_arg(ap, signed int));
}
