/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:59:14 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 17:05:13 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse_flags(t_fmt *fmt, const char *f)
{
	while (*f != '\0')
	{
		if (*f == '+' && f++)
			fmt->f_plus = true;
		else if (*f == '-' && f++)
			fmt->f_minus = true;
		else if (*f == '0' && f++)
			fmt->f_zero = true;
		else if (*f == '#' && f++)
			fmt->f_octo = true;
		else if (*f == ' ' && f++)
			fmt->f_space = true;
		else
			break ;
	}
	return (f);
}
