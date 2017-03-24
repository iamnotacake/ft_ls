/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:14:06 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 17:19:54 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse_mod(t_fmt *fmt, const char *f)
{
	if (STRNCMP(f, "hh", 2) == 0 && (f += 2))
		STRCPY(fmt->mod, "hh");
	else if (STRNCMP(f, "h", 1) == 0 && (f += 1))
		STRCPY(fmt->mod, "h");
	else if (STRNCMP(f, "ll", 2) == 0 && (f += 2))
		STRCPY(fmt->mod, "ll");
	else if (STRNCMP(f, "l", 1) == 0 && (f += 1))
		STRCPY(fmt->mod, "l");
	else if (STRNCMP(f, "j", 1) == 0 && (f += 1))
		STRCPY(fmt->mod, "j");
	else if (STRNCMP(f, "z", 1) == 0 && (f += 1))
		STRCPY(fmt->mod, "z");
	return (f);
}
