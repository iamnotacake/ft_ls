/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:21:40 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 17:38:36 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse(t_fmt *fmt, const char *f, va_list ap)
{
	const char	*old;

	BZERO(fmt, sizeof(t_fmt));
	while (true)
	{
		old = f;
		f = parse_flags(fmt, f);
		f = parse_width(fmt, f, ap);
		f = parse_precision(fmt, f, ap);
		f = parse_mod(fmt, f);
		if (old == f)
			break ;
	}
	if (*f != '\0')
		fmt->type = *(f++);
	return (f);
}
