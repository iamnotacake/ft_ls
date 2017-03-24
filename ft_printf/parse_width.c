/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:59 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 18:03:58 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse_width(t_fmt *fmt, const char *f, va_list ap)
{
	if (*f == '*')
	{
		f++;
		fmt->has_width = true;
		fmt->width = va_arg(ap, int);
	}
	else if ('1' <= *f && *f <= '9')
	{
		fmt->has_width = true;
		fmt->width = 0;
		while ('0' <= *f && *f <= '9')
			fmt->width = fmt->width * 10 + *(f++) - '0';
	}
	return (f);
}
