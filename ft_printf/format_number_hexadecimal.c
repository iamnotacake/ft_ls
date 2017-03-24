/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number_hexadecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:08:32 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 19:22:40 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_number_hexadecimal(t_fmt *fmt, va_list ap)
{
	char		*number;
	char		sign[3];

	number = uintmax_to_any(pull_number_unsigned(fmt, ap),
							16, fmt->type == 'X');
	number = format_number_prep_zeros(fmt, number);
	if (fmt->f_octo || fmt->type == 'p')
		STRCPY(sign, fmt->type == 'X' ? "0X" : "0x");
	else
		sign[0] = '\0';
	if (fmt->has_precision && fmt->precision == 0 && number_is_zero(number))
	{
		sign[0] = '\0';
		number[0] = '\0';
	}
	if ((!fmt->f_minus && !fmt->f_zero && fmt->has_width) ||
		(!fmt->f_minus && fmt->f_zero && fmt->has_width && fmt->has_precision))
		APPEND_CHAR_N(' ', fmt->width - STRLEN(number) - (sign[0] ? 2 : 0));
	if ((sign[0] != '\0' && !number_is_zero(number)) || fmt->type == 'p')
		APPEND_STRING(sign);
	if (!fmt->f_minus && fmt->f_zero && fmt->has_width && !fmt->has_precision)
		APPEND_CHAR_N('0', fmt->width - STRLEN(number) - (sign[0] ? 2 : 0));
	APPEND_STRING(number);
	if (fmt->f_minus && fmt->has_width)
		APPEND_CHAR_N(' ', fmt->width - STRLEN(number) - (sign[0] ? 2 : 0));
}
