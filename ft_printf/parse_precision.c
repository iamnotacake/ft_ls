/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:11:51 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 18:54:23 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse_precision(t_fmt *fmt, const char *f, va_list ap)
{
	if (*f == '.')
	{
		f++;
		fmt->has_precision = true;
		fmt->precision = 0;
		if (*f == '*')
		{
			f++;
			fmt->precision = va_arg(ap, int);
		}
		else
		{
			while ('0' <= *f && *f <= '9')
				fmt->precision = fmt->precision * 10 + *(f++) - '0';
		}
	}
	return (f);
}
