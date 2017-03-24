/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number_octal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:35 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 19:59:23 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_number_octal(t_fmt *fmt, va_list ap)
{
	char		*number;
	char		sign[3];

	number = uintmax_to_any(pull_number_unsigned(fmt, ap), 8, false);
	number = format_number_prep_zeros(fmt, number);
	if (fmt->has_precision && fmt->precision == 0 && number_is_zero(number))
		number[0] = '\0';
	if (fmt->f_octo)
		STRCPY(sign, "0");
	else
		sign[0] = '\0';
	if ((!fmt->f_minus && !fmt->f_zero && fmt->has_width) ||
		(!fmt->f_minus && fmt->f_zero && fmt->has_width && fmt->has_precision))
		APPEND_CHAR_N(' ', fmt->width - STRLEN(number) - (sign[0] ? 1 : 0));
	if (sign[0] != '\0' && !number_is_zero(number))
		APPEND_STRING(sign);
	if (fmt->f_octo && fmt->has_precision && fmt->precision == 0 &&
		number_is_zero(number))
		APPEND_CHAR('0');
	if (!fmt->f_minus && fmt->f_zero && fmt->has_width && !fmt->has_precision)
		APPEND_CHAR_N('0', fmt->width - STRLEN(number) - (sign[0] ? 1 : 0));
	APPEND_STRING(number);
	if (fmt->f_minus && fmt->has_width)
		APPEND_CHAR_N(' ', fmt->width - STRLEN(number) - (sign[0] ? 1 : 0));
}
