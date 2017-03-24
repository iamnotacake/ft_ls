/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:11:51 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 19:15:37 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_char(t_fmt *fmt, va_list ap)
{
	char		chr;

	chr = va_arg(ap, int);
	if (fmt->has_width && !fmt->f_minus)
		APPEND_CHAR_N(fmt->f_zero ? '0' : ' ', fmt->width - 1);
	APPEND_CHAR(chr);
	if (fmt->has_width && fmt->f_minus)
		APPEND_CHAR_N(' ', fmt->width - 1);
}
