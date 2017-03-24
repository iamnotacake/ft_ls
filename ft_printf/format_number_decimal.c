/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:03:24 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 16:48:35 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*format_number_prep_zeros(t_fmt *fmt, char *number)
{
	while (fmt->has_precision && (int)STRLEN(number) < fmt->precision)
		*(--number) = '0';
	return (number);
}

bool			number_is_zero(const char *number)
{
	while (*number != '\0')
		if (*(number++) > '0')
			return (false);
	return (true);
}

void			format_number_decimal(t_fmt *fmt, va_list ap)
{
	char		*number;
	char		sign;

	sign = '\0';
	number = IS_DECIMAL(fmt)
			? intmax_to_any(pull_number_signed(fmt, ap), 10, false, &sign)
			: uintmax_to_any(pull_number_unsigned(fmt, ap), 10, false);
	number = format_number_prep_zeros(fmt, number);
	if (fmt->has_precision && fmt->precision == 0 && number_is_zero(number))
		number[0] = '\0';
	if (fmt->f_space && sign != '-' && ((!fmt->has_width) ||
		(fmt->has_width && fmt->has_precision)))
		sign = ' ';
	if (fmt->f_plus && sign != '-')
		sign = '+';
	if ((!fmt->f_minus && !fmt->f_zero && fmt->has_width) ||
		(!fmt->f_minus && fmt->f_zero && fmt->has_width && fmt->has_precision))
		APPEND_CHAR_N(' ', fmt->width - STRLEN(number) - (sign ? 1 : 0));
	if (sign != '\0' && fmt->type != 'u' && fmt->type != 'U')
		APPEND_CHAR(sign);
	if (!fmt->f_minus && fmt->f_zero && fmt->has_width && !fmt->has_precision)
		APPEND_CHAR_N('0', fmt->width - STRLEN(number) - (sign ? 1 : 0));
	APPEND_STRING(number);
	if (fmt->f_minus && fmt->has_width)
		APPEND_CHAR_N(' ', fmt->width - STRLEN(number) - (sign ? 1 : 0));
}
